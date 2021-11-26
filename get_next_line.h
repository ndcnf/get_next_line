// PROTEGER LE FICHIER POUR LA NORMINETTE !
#include <unistd.h>
#include <fcntl.h>

// CES INCLUDES SONT POUR open() et close()
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/uio.h>

/*UNIQUEMENT POUR INFO. SUPPRIMER ENSUITE.
ssize_t	read(int fd, void *buf, size_t count);
int		open(const char *pathname, int flags);
int		close(int fd);
*/
char	*get_next_line(int fd);
