#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    char addr[] = "1.2.3.4";

    unsigned long conv_addr = inet_addr(addr);

    printf("%#lx\n", conv_addr);

}