#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>



int main()
{
    char addr[] = "127.232.124.79";
    struct sockaddr_in addr_inet;
    inet_aton(addr, &addr_inet.sin_addr);

    printf("%#x \n", addr_inet.sin_addr.s_addr);

}