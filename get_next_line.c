/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:06:35 by nchennaf          #+#    #+#             */
/*   Updated: 2021/11/30 16:31:30 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	i; // ce i ne devrait peut-etre pas etre static. Position actuelle dans le buffer uniquement.
	static int	j; // celui qui voyage entre les mondes, le gardien de la position interfonctions
	char		*buffer; //static ou pas static ?
	char		*line;
	ssize_t		*been_read;

	buffer = (char*)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (NULL);
	been_read = read(fd, buffer, BUFFER_SIZE);
	while (been_read > 0)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
		{
			line[i] =
			i++;
		}
		//return (); //retourner la ligne suivante
	}
	buffer[i++] = '\0'; // ajouter le '0' final et incrementer ensuite le i pour l'instruction suivante
	j = i + 1] // position de '\n' + 1 pour remettre le curseur au bon endroit pour le prochain appel
	return (0); // return NULL eventuellement ? Si read <= 0, c'est une erreur, non ?
}
