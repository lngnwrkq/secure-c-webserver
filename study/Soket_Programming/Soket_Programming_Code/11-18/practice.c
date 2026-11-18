#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main ()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    char addr1[] = "1.2.3.4";
    char port1[] = "9190";

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    inet_aton(addr1, addr.sin_addr.s_addr);
    addr.sin_port=hton(atoi(port1));

}
//From Socket Creation to Address Assignment