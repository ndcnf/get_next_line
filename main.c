#include "get_next_line.h"
#include <stdio.h>

/*int main()
{
	int fd;
	int	i;

	fd = open("test.txt", O_RDONLY);
	if (fd > 0)
	{
		i = 15;
		while (i--)
			printf("%s", get_next_line(fd));
	}
	else
		return(-1);
	close(fd);
	return (0);
}*/

int    main(int argc, char **argv)
{
    int    fd = open(argv[1], O_RDONLY);
    char    *retour = get_next_line(fd);
    int    i = 1;
    (void)argc;
    while (retour != NULL)
    {
        printf("%3i Retour fonction =%s",i , retour);
        //write(1, "/", 1);
        i++;
        retour = get_next_line(fd);
    }
        printf("%3i Retour fonction =%s",i , retour);
}
