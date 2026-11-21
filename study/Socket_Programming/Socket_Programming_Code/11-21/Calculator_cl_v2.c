#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

// Communication protocol:
// The client sends operands and an operator as a fixed-size 100-byte message.
// The server receives exactly 100 bytes for each calculation request.
// The server sends the calculation result as a 4-byte integer.
// The client receives the 4-byte result.

#define BUF 1024

int main(int argc, char *argv[])
{
    int sock;
    int len = 0;
    int check_p = 0;
    int count = 0;
    struct sockaddr_in addr_sv;
    char op[BUF] = "";  // Buffer for storing the input operands and operator
    int INT_op[BUF];    // Buffer for receiving the calculation result from the server
    char temp[10];      // Temporary buffer for each operand before appending it to op

    sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&addr_sv, 0, sizeof(addr_sv));
    addr_sv.sin_family = PF_INET;
    addr_sv.sin_addr.s_addr = inet_addr(argv[1]);
    addr_sv.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&addr_sv, sizeof(addr_sv)) == -1)
    {
        printf("Failed to connect to the server\n");
        exit(1);
    }
    else
    {
        printf("Connected to the server\n");
    }

    while (1)
    {
        int i = 0;
        int ch;
        char operator[2];  // Buffer for storing the arithmetic operator

        printf("Operand count: ");
        scanf("%d", &count);

        // Clear the remaining input, including the newline character,
        // to prevent it from being read by the next fgets() call.
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
        }

        // Clear the operand buffer before starting a new calculation.
        memset(&op, 0, sizeof(op));

        for (i = 0; i < count; i++)
        {
            printf("Operand %d (quit = q): ", i + 1);

            fgets(temp, 10, stdin);

            // Remove the trailing newline character, if present.
            temp[strcspn(temp, "\n")] = '\0';

            if (strchr(temp, 'q') != NULL)
            {
                write(sock, "q", 1);
                close(sock);
                exit(1);
            }

            // Append the operand and a space to the message buffer.
            strcat(op, temp);
            strcat(op, " ");
        }

        printf("Operator: ");
        scanf("%1s", operator);

        // Append the operator to complete the request message.
        strcat(op, operator);

        // Send a fixed-size 100-byte calculation request.
        write(sock, op, 100);

        check_p = 0;

        // Clear the result buffer before receiving a new result.
        memset(&INT_op, 0, sizeof(INT_op));

        while (check_p < 4)
        {
            len = 0;

            // Cast INT_op to char* for byte-level pointer arithmetic.
            // If only 2 bytes are received, check_p becomes 2.
            // INT_op + 2 would move 8 bytes on a system with 4-byte integers.
            // (char*)INT_op + 2 moves exactly 2 bytes instead.
            // This allows the next read() call to continue at the correct position.
            len = read(sock, (char*)INT_op + check_p, 4 - check_p);

            if (len <= 0)
            {
                printf("Failed to receive data from the server\n");
                break;
            }

            // Update the total number of received bytes.
            check_p = check_p + len;
        }

        printf("Calculation result: %d\n", INT_op[0]);
    }

    close(sock);
}