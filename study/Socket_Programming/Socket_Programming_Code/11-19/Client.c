#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUF 1024

int main(int argc, char *argv[]) // Receives the program name, server IP address, and port number as arguments
{
    int sock;
    char message[BUF];
    int str_len;
    struct sockaddr_in addr_sv;

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

    while(1)
    {
        fputs("Enter a message to send to the server (q to quit): ", stdout);
        fgets(message, BUF, stdin);

        // fgets() includes the newline character, so replace it with '\0'.
        // gets_s() is not supported in this environment.
        message[strcspn(message, "\n")] = '\0';

        if (strcmp(message, "q") == 0)
        {
            break;
        }

        write(sock, message, strlen(message));

        // Read up to 1023 bytes and store the number of bytes read in str_len.
        str_len = read(sock, message, BUF-1);

        if (str_len == -1)
        {
            printf("read() function error\n");
            break;
        }

        // Add the null terminator after the received data.
        // Any unread bytes remain available for the next read() call.
        message[str_len] = '\0';

        printf("Message received from server: %s\n", message);
    }
    close(sock);
}