#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUF 1024

int main()
{
    int sv_sock;
    int cl_sock;
    int str_len; // Stores the number of bytes returned by read() to detect connection closure
    char port[] = "8080";
    char message[BUF];
    struct sockaddr_in addr_sv, addr_cl;
    socklen_t cl_addr_size; // Stores the client address size required by accept()

    sv_sock = socket(PF_INET, SOCK_STREAM, 0); // Creates a TCP socket
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

    cl_addr_size = sizeof(addr_cl); // Sets the client address buffer size for accept()

    while(1)
    {
        int sv_c = 0;

        cl_sock = accept(sv_sock, (struct sockaddr *)&addr_cl, &cl_addr_size);
        if (cl_sock == -1)
        {
            printf("Failed to accept client connection\n");
            exit(1);
        }

        // read() returns the number of bytes read; 0 indicates EOF.
        // Using != 0 would also treat an error return (-1) as true.
        while((str_len = read(cl_sock, message, BUF)) > 0)
        {
            write(cl_sock, message, str_len);
        }

        close(cl_sock);

        printf("Continue with the next client? (1 = NO): ");
        scanf("%d", &sv_c);

        if (sv_c == 1)
        {
            break;
        }
    }

    close(sv_sock);
}