// PROTEGER LE FICHIER POUR LA NORMINETTE !
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

#define	BUFFER_SIZE 100
char	*get_next_line(int fd);
