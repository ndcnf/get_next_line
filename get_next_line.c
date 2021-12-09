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

int		line_len(char *s)
{
	static int	i; // oh yeah, on se souvient ou on en etait
	int			j; // le i du passe

	j = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (j);
		}
		i++;
		j++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static int	i = 1; 					// Position actuelle dans la ligne a retourner
	static char	buffer[BUFFER_SIZE + 1];	// celui qui voyage entre les mondes, le gardien de la position interfonctions.
	char	*line;		// la ligne a retourner. Gardons la propre. La star de la fonction.
	ssize_t		been_read;	// la taille de ce qui a ete lu
	static char	*leftovers;
	static int	welcome = 1; // premiere entree dans la fonction
	int			j;
	size_t		b_len;

	// *buffer = 0; // par defaut, la valeur devrait etre 0 pour une variable statique
		
	/*	On va d'abord verifier qu'il n'y a rien dans le buffer,
	pas de reste d'un appel precedent */

	//i = 1; // avec welcome
	j = 0;
	//welcome = 1; // si !static
	b_len = line_len(buffer);
	while (i > 0)
	{
		if (welcome == 1)
		{
			i = 0;
			welcome = 0;
			line = NULL;
			leftovers = buffer; // avant: buffer /ou NULL/"" ?
		}
		else if (leftovers[j]) // avant buffer[j]
		{
			i = 0;
			//*buffer = *leftovers; // semblait juste, mais plus maintenant
		}

		if (leftovers[j] == 0)
		{
			been_read = read(fd, buffer, BUFFER_SIZE);
			//line = (char*)ft_calloc(line_len(buffer), sizeof(char));
			line = (char*)ft_calloc(ft_strlen(buffer), sizeof(char));
			if (!line)
				return (NULL);
			leftovers = ft_strdup(buffer);
			j = 0;
		}
// ICI une question. La string de read() doit etre testee ici.
		while (j < (BUFFER_SIZE))
		{
			if (leftovers[j] == '\n')
			{
				line[i] = leftovers[j];
				//i = 0; //utile si static
				leftovers = ft_substr(buffer, (i + 1), (BUFFER_SIZE - i));
				//ft_strdup(line);
				return (line);
			}
			else
			{
				line[i++] = leftovers[j++];
				//i++;
				//j++;
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
