#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd;

    fd = open("myfile.txt", O_RDONLY);
    printf("[%d]\n", fd);
    while (fd != -1)
    {
        printf("%s", get_next_line(fd));

    }
    return (0);  
}