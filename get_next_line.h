// PROTEGER LE FICHIER POUR LA NORMINETTE !
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h> // enleve ca

#define	BUFFER_SIZE 100
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
int		line_len(char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
