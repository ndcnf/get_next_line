// PROTEGER LE FICHIER POUR LA NORMINETTE !
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdlib.h>

//#define	BUFFER_SIZE 100
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int     line_len(char *s);
