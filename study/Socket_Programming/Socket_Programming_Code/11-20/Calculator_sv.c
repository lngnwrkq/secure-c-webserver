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
    int str_len = 0; 
    int op[BUF];
    char port[] = "8080";
    char message[BUF]="";
    char *operator;
    int int_operator = 0;
    int sv_c = 0;
    struct sockaddr_in addr_sv, addr_cl;
    socklen_t cl_addr_size; 

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


    cl_addr_size = sizeof(addr_cl); 

    while(1)
    {
        int sv_c = 0;

        cl_sock = accept(sv_sock, (struct sockaddr *)&addr_cl, &cl_addr_size);
        if (cl_sock == -1)
        {
            printf("Failed to accept client connection\n");
            exit(1);
        }
        int check_p = 0;
        while(check_p < 100)
        {
            str_len = read(cl_sock, &message[check_p], 100-check_p);
            if (str_len <= 0)
        {
            printf("read()함수 호출 실패\n");
            break;
        }
            check_p += str_len;
        }
        
        message[100] = '\0';
        printf("%s\n", message);
        char *ptr = strtok(message, " ");
        int count=0;
        int i = 0;
        for (i = 0; i<100; i++)
        {
            if (ptr == NULL)
            {
                break;
            }
            if (strcmp(ptr, "+") == 0 || strcmp(ptr, "-") == 0 || strcmp(ptr, "*") == 0)
            {
                operator = ptr;
                break;
            }
            op[i] = atoi(ptr);
            ptr = strtok(NULL, " ");
            count++;
        }
        
        


        if (strchr(operator, '+') != 0)
        {
            int_operator = 1;
        }
        else if (strchr(operator, '-') != 0)
        {
            int_operator = 2;
        }
        else
        {
            int_operator = 3;
        }
        int sum = 0;
        switch (int_operator)
        {
        case 1:
            int i=0;
            while (i != count)
            {
                sum += op[i];
                i++;
            }
            break;
        case 3:
            int j=0;
            sum = 1;
            while (j != count)
            {
                
                sum *= op[j];
                j++;
            }
            break;
        default:
        int k=0;
            sum = op[0];
            while (k != count)
            {
                sum -= op[k+1];
                k++;
            }
            break;
        }
        write(cl_sock, &sum, sizeof(sum));

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