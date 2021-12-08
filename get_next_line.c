/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:06:35 by nchennaf          #+#    #+#             */
/*   Updated: 2021/12/08 22:03:12 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*leftovers(char *s, char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = NULL;
	while (buffer[i])
	{
		if (buffer[i] != s[j])
		{
			res = &buffer[i];
		}
		j++;
		i++;
	}
	return (s);
}*/

char	*get_next_line(int fd)
{
	static int	i = 1; 					// Position actuelle dans la ligne a retourner
	static char	buffer[BUFFER_SIZE + 1];	// celui qui voyage entre les mondes, le gardien de la position interfonctions.
	static char	*line;		// la ligne a retourner. Gardons la propre. La star de la fonction.
	//ssize_t		been_read;	// la taille de ce qui a ete lu
	static char	*lefties;
	static int	welcome = 1; // premiere entree dans la fonction
	int			j;
	size_t		b_len;

	//*buffer = 0; // par defaut, la valeur devrait etre 0 pour une variable statique
		/*	On va d'abord verifier qu'il n'y a rien dans le buffer,
		pas de reste d'un appel precedent

		Ici, on part sur le fait qu'il est vide (n'a que des zeros)*/
	//i = 1; // avec welcome
	j = 0;
	//welcome = 1;
	b_len = line_len(buffer);
	while (i > 0)
	{
		if (welcome == 1)
		{
			i = 0;
			welcome = 0;
			line = NULL;
			lefties = buffer;
		}
		else if (buffer[j])
		{
			i = 0;
			*buffer = *lefties; // semble juste
		}

		if (buffer[j] == 0)
		{
			read(fd, buffer, BUFFER_SIZE);
			line = (char*)ft_calloc(line_len(buffer), sizeof(char));
			if (!line)
				return (NULL);
			//been_read = read(fd, buffer, BUFFER_SIZE);
			j = 0;
		}
// ICI une question. La string de read() doit etre testee ici.
		while (j < (BUFFER_SIZE))
		{
			if (buffer[j] == '\n')
			{
				line[i] = buffer[j];
				//i = 0; //utile si static
				lefties = ft_substr(buffer, (i + 1), b_len);
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
