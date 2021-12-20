#include "get_next_line.h"

int	the_reader(char **leftovers, int fd)
{
	int		red_bean;
	char	buffer[BUFFER_SIZE + 1];
	int		eof;

	eof = 0;
	if (!*leftovers)
		*leftovers = ft_strdup("");
	while (!ft_strchr(*leftovers, '\n') && !eof)
	{
		red_bean = read(fd, buffer, BUFFER_SIZE);
		buffer[red_bean] = '\0';
		if (red_bean != BUFFER_SIZE)
		{
			eof = 1;
			*leftovers = ft_strdup(buffer);
			break ;
		}
		*leftovers = ft_strjoin(*leftovers, buffer); // attention contient un malloc
	}
	return (eof);
}

char	*the_oneliner(char **leftovers)
{
	int		i;
	char	*line;
	char	*tempura;

	i = 0;
	while ((*leftovers)[i] != '\n' && (*leftovers)[i])
		i++;
	if ((*leftovers)[i] == '\n')
		line = ft_substr(*leftovers, 0, ++i); //i++ et (..., ..., i);
	else
		line = ft_strdup(*leftovers);
	tempura = *leftovers;
	*leftovers = ft_substr(*leftovers, i, (ft_strlen(*leftovers) - i)); // pour remplacer le \n de la ligne precedente
	free(tempura);
	return (line);
}
/*
char	the_cleaner(char *s)
{

}
*/

char	*get_next_line(int fd)
{
	static char	*leftovers;
	int			eof;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	eof = the_reader(&leftovers, fd);
	line = the_oneliner(&leftovers);
	if (eof && leftovers[0] == '\0' && line[0] == '\0')
		return (NULL);
	return (line);
}
