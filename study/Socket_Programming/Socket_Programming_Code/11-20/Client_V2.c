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
    int str_len = 0;
    int str_size = 0; //보냈던 메시지의 크기 저장
    int str_check_p = 0; //현재까지 받은 메시지의 크기를 기억
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
        str_check_p = 0;

  
        message[strcspn(message, "\n")] = '\0';

        if (strcmp(message, "q") == 0)
        {
            break;
        }

        str_size = write(sock, message, strlen(message)); //메시지 크기 계산
        while(str_check_p < str_size) 
        //서버측에서 read()가 한번에 받는다는 보장이 없으니 에코 클라이언트에서 보냈던 메시지 크기를 기억하여 read()를 여러번 호출하여 메세지 전부 수신
        {
             
            str_len = 0;
            str_len = read(sock, &message[str_check_p], BUF-1-str_check_p); //현재받은 메시지의 다음부터 저장 및 크기에서 빼주기
            if (str_len <= 0)
            {
            printf("read() function error\n");
            break;
            }
            str_check_p = str_check_p + str_len; // 누적 메시지 확인
        }
    
        message[str_check_p] = '\0';

        printf("Message received from server: %s\n", message);
    }
    close(sock);
}