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
	int			i; 					// Position actuelle dans la ligne a retourner
	static char	buffer[BUFFER_SIZE + 1];	// celui qui voyage entre les mondes, le gardien de la position interfonctions.
	char		*line;		// la ligne a retourner. Gardons la propre. La star de la fonction.
	ssize_t		been_read;	// la taille de ce qui a ete lu
	int			welcome; // premiere entree dans la fonction
	int			j;

	/*	est-ce que l'initialisation ne se fera qu'une seule fois,
		reellement ou est-ce que ca fonctionne uniquement lors de
		la declaration-assignation ? */

	//*buffer = 0; // par defaut, la valeur devrait etre 0 pour une variable statique
		/*	On va d'abord verifier qu'il n'y a rien dans le buffer,
		pas de reste d'un appel precedent

		Ici, on part sur le fait qu'il est vide (n'a que des zeros)*/
	i = 1;
	j = 0;
	welcome = 1;
	line = NULL;
	while (i > 0)
	{
		if (welcome == 1)
		{
			i = 0;
			welcome = 0;
		}

		j = 0;	
		if (buffer[j] == 0)
		{
			line = (char*)ft_calloc(line_len(buffer), sizeof(char));
			if (!line)
				return (NULL);
			been_read = read(fd, buffer, BUFFER_SIZE);
		}
// ICI une question. La string de read() doit etre testee ici.
		while (buffer[j])
		{
			if (buffer[j] == '\n')
			{
				line[i] = buffer[j];
				//i = 0; utile si static
				return (line);
			}
			else
			{
				line[i] = buffer[j];
				i++;
				j++;
			}
		}

	}
	return (0); // pas sure de celui-ci.
}

/*

	while (buffer[i] == 0)
	{
		//line = NULL;
		line = (char*)ft_calloc(line_len(buffer), sizeof(char));
		if (!line)
			return (NULL);
		been_read = read(fd, buffer, BUFFER_SIZE);
	}

	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			line[i] = buffer[i];
			i = 0;
			return (line);
		}
		else
		{
			line[i] = buffer[i];
			i++;
			buffer[i]++;
		}
	}







}

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
