#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int	i;

	fd = open("myfile.txt", O_RDONLY);
	if (fd > 0)
	{
		i = 2;
		while (i--)
			printf("%s", get_next_line(fd));
	}
	else
		return(-1);
	close(fd);
	return (0);
}
