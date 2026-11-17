// you must coplie this code after running low.open.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[100];

    fd = open("data.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("error");
        exit(1);
    }
    if (fd = read(fd, buf, 100) == -1)
    {
        printf("error");
        exit(1);
    }
    printf("file data: %s", buf);
    close(fd);
}