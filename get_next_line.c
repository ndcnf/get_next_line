/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:30:53 by nchennaf          #+#    #+#             */
/*   Updated: 2021/12/22 14:38:15 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	the_reader(char **leftovers, int fd)
{
	int		red_bean;
	char	buffer[BUFFER_SIZE + 1];
	int		eof;
	char	*tempura;

	eof = 0;
	if (!*leftovers)
		*leftovers = ft_strdup("");
	while (!ft_strchr(*leftovers, '\n') && !eof)
	{
		red_bean = read(fd, buffer, BUFFER_SIZE);
		buffer[red_bean] = '\0';
		if (red_bean < BUFFER_SIZE)
			eof = 1;
		tempura = *leftovers;
		*leftovers = ft_strjoin(*leftovers, buffer);
		free(tempura);
	}
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
		i++;
	if (i == 0)
		return (NULL);
	line = ft_substr(*leftovers, 0, i);
	tempura = *leftovers;
	*leftovers = ft_substr(*leftovers, i, (ft_strlen(*leftovers) - i));
	free(tempura);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	the_reader(&leftovers, fd);
	line = the_oneliner(&leftovers);
	if (!line)
	{
		free(line);
		free(leftovers);
		leftovers = NULL;
		return (NULL);
	}
	return (line);
}
