#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_IP = 0x12345678;
    unsigned long net_IP;

    printf("%#x %#lx\n", host_port, host_IP);


    net_port = htons(host_port);
    net_IP = htonl(host_IP);

    printf("%#x %#lx", net_port, net_IP);
}
//my cpu use little Endian