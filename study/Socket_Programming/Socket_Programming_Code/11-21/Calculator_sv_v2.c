#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUF 1024

// Calculator server communication protocol:
// The client sends operands and an operator in a fixed-size 100-byte message.
// The server receives exactly 100 bytes for each calculation request.
// The server sends the calculation result as a 4-byte integer.
// The client receives the 4-byte result.
// The client can also send 'q' to request termination.

int main()
{
    int sv_sock;
    int cl_sock;
    int str_len = 0;         // Number of bytes received by read()
    char port[] = "8080";    // Server port number
    int op[BUF] = {0};       // Array for storing integer operands
    char message[BUF] = "";  // Buffer for receiving the request message
    char *operator;          // Pointer to the arithmetic operator
    int int_operator = 0;    // Integer value used to identify the operator

    struct sockaddr_in addr_sv, addr_cl;
    socklen_t cl_addr_size;

    sv_sock = socket(PF_INET, SOCK_STREAM, 0);

    if (sv_sock == -1)
    {
        printf("Failed to create socket\n");
        exit(1);
    }

    memset(&addr_sv, 0, sizeof(addr_sv));

    addr_sv.sin_family = AF_INET;
    addr_sv.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_sv.sin_port = htons(atoi(port));

    if (bind(sv_sock, (struct sockaddr*)&addr_sv, sizeof(addr_sv)) == -1)
    {
        printf("Failed to bind socket address\n");
        exit(1);
    }

    if (listen(sv_sock, 5) == -1)
    {
        printf("Failed to listen for connections\n");
        exit(1);
    }

    cl_addr_size = sizeof(addr_cl);
    cl_sock = accept(sv_sock, (struct sockaddr*)&addr_cl, &cl_addr_size);
    
    if (cl_sock == -1)
    {
        printf("Failed to accept client connection\n");
        exit(1);
    }

    while (1)
    {
        int check_p = 0;  // Total number of bytes received

        // Clear the message buffer before receiving a new request.
        memset(&message, 0, sizeof(message));

        // Receive the complete 100-byte request.
        while (check_p < 100)
        {
            // Store new data after the previously received bytes.
            // Read only the remaining number of bytes.
            str_len = read(cl_sock, &message[check_p], 100 - check_p);

            if (str_len <= 0)
            {
                printf("Connection closed or read() failed\n");
                break;
            }

            // Stop the server if the received message contains 'q'.
            if (strchr(message, 'q') != NULL)
            {
                printf("Client requested termination\n");

                close(cl_sock);
                close(sv_sock);

                exit(1);
            }

            // Update the total number of received bytes.
            check_p += str_len;
        }

        // Stop processing if the complete request was not received.
        if (check_p != 100)
        {
            printf("Client disconnected or incomplete message\n");
            break;
        }

        // Split the received message into operands and an operator.
        char *ptr = strtok(message, " ");

        int count = 0;  // Number of operands
        int i = 0;

        operator = NULL;  // Reset the operator pointer

        for (i = 0; i < 100; i++)
        {
            if (ptr == NULL)
            {
                break;
            }

            // Check whether the current token is an operator.
            if (strcmp(ptr, "+") == 0 ||
                strcmp(ptr, "-") == 0 ||
                strcmp(ptr, "*") == 0)
            {
                operator = ptr;
                break;
            }

            // Convert the operand string into an integer.
            op[i] = atoi(ptr);

            // Move to the next token separated by a space.
            ptr = strtok(NULL, " ");

            count++;
        }

        // Reject a request without an operator or operands.
        if (operator == NULL || count == 0)
        {
            printf("Invalid request\n");
            break;
        }

        // Identify the arithmetic operator.
        if (strchr(operator, '+') != NULL)
        {
            int_operator = 1;
        }
        else if (strchr(operator, '-') != NULL)
        {
            int_operator = 2;
        }
        else
        {
            int_operator = 3;
        }

        int sum = 0;  // Final calculation result

        switch (int_operator)
        {
        case 1:
            // Addition
            {
                int i = 0;

                while (i != count)
                {
                    sum += op[i];
                    i++;
                }
            }
            break;

        case 3:
            // Multiplication
            {
                int j = 0;

                // Start with 1 because multiplying by 0 always gives 0.
                sum = 1;

                while (j != count)
                {
                    sum *= op[j];
                    j++;
                }
            }
            break;

        default:
            // Subtraction
            {
                int k = 1;

                // Start with the first operand instead of 0.
                sum = op[0];

                while (k < count)
                {
                    sum -= op[k];
                    k++;
                }
            }
            break;
        }

        // Send the calculation result to the client.
        write(cl_sock, &sum, sizeof(sum));
    }

    close(cl_sock);
    close(sv_sock);
}