#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUF 1024
int main(int argc, char *argv[]) 
{
    int sock;
    char message[BUF];
    int len= 0;
    int size = 0; 
    int check_p = 0; 
    int count = 0;
    struct sockaddr_in addr_sv;
    char op[BUF] = "";
    int INT_op[BUF];

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

    char temp[10];


    int i = 0;
    printf("Operand count: ");
    scanf("%d", &count);
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
    char operator[2];
    while(1)
    {   
        memset(&op, 0, sizeof(op));
        for (i=0; i<count; i++)
        {
            printf("Operand %d: ", i+1);
            fgets(temp, 10, stdin);
            temp[strcspn(temp, "\n")] = '\0';
            strcat(op,temp);
            strcat(op," ");
        }
        
        printf("Operator : ");
        scanf("%1s", operator);
        strcat(op,operator);
        
        

        write(sock, op, BUF);
        check_p = 0;
        while(check_p < 4) 
        {
             
            len = 0;
            len = read(sock, (char*)INT_op + check_p, 4-check_p); 
            if (len <= 0)
            {
            printf("read() function error\n");
            break;
            }
            check_p = check_p + len; 
        }

        printf("Message received from server: %d\n", INT_op[0]);
    }
    close(sock);
}