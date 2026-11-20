#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[] = "Hello, World!";
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC,0644);
    if (fd == -1)
    {
        printf("error");
        exit(1);
    }
    printf("file descriptor: %d \n", fd);

    if (write(fd, buf, sizeof(buf)) == -1)
    {
        printf("error");
        exit(1);
    }
    close(fd);
    return 0;


}