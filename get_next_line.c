/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:06:35 by nchennaf          #+#    #+#             */
/*   Updated: 2021/12/01 15:26:36 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	i; 			// Position actuelle dans la ligne a retourner
	static char	*buffer;	// celui qui voyage entre les mondes, le gardien de la position interfonctions.
	char		*line;		// la ligne a retourner. Gardons la propre. La star de la fonction.
	//ssize_t		*been_read;	// la taille de ce qui a ete lu

	/*	est-ce que l'initialisation ne se fera qu'une seule fois,
		reellement ou est-ce que ca fonctionne uniquement lors de
		la declaration-assignation ? */

	//*buffer = 0; // par defaut, la valeur devrait etre 0 pour une variable statique
		/*	On va d'abord verifier qu'il n'y a rien dans le buffer,
		pas de reste d'un appel precedent

		Ici, on part sur le fait qu'il est vide (n'a que des zeros)*/
	while (*buffer == 0)
	{
		line = NULL;
		buffer = (char*)ft_calloc((sizeof(char) * BUFFER_SIZE) + 1, BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
	}

	while (*buffer)
	{
		if (*buffer == '\n')
		{
			line[i] = *buffer;
			i = 0;
			return (line);
		}
		else
		{
			line[i] = *buffer;
			i++;
			*buffer++;
		}
	}







}
/*

	while (been_read > 0)
	{
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
		{
			line[i] = *buffer; // line[i++] = *buffer++; pour eviter les 2 lignes en dessous
			i++;
			*buffer++;
		}
		//return (); //retourner la ligne suivante
	}
	}
	return (0); // return NULL eventuellement ? Si read <= 0, c'est une erreur, non ?
}
*/
