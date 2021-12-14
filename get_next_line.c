/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:06:35 by nchennaf          #+#    #+#             */
/*   Updated: 2021/12/14 17:14:01 by nchennaf         ###   ########.fr       */
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
	static int	i; 							// Position actuelle dans la ligne a retourner
	static char	buffer[BUFFER_SIZE + 1];	// celui qui voyage entre les mondes, le gardien de la position interfonctions.
	char		*line;						// la ligne a retourner. Gardons la propre. La star de la fonction.
	ssize_t		been_read;					// la taille de ce qui a ete lu
	static char	*leftovers;
	int			welcome;				// premiere entree dans la fonction
	int			j;
	char		*res;

	welcome = 1;
	if (i > 0)
		i = 0;
	else
		i = 1;
	j = 0;

	//if (fd > 1023)
	//	return (NULL);

	while (i > 0)
	{
		if (welcome == 1)
		{
			i = 0;
			welcome = 0;
			res = (char*)ft_calloc(line_len(buffer), sizeof(char));
			line = (char*)ft_calloc(line_len(buffer), sizeof(char));
			//if (!line)
			//	return (NULL);
			if (!leftovers)
				leftovers = ft_strdup(buffer);
		}

		if (leftovers[j] == 0)
		{
			been_read = read(fd, buffer, BUFFER_SIZE);
			if (!line)
				return (NULL);
			leftovers = ft_strdup(buffer);
			j = 0;
		}

		while (j < (BUFFER_SIZE))
		{
			if (leftovers[j] == '\0' && been_read >= 0)
			{
				//;
				printf("AH-HA !");
				//leftovers = ft_substr(leftovers, (j + 1), ft_strlen(leftovers));
			//leftovers = ft_substr(leftovers, (i + 1), (BUFFER_SIZE - i));
				//break;
			}
			else if (leftovers[j] == '\n' || been_read == -1)
			{
				line[i] = leftovers[j];
				leftovers = ft_substr(leftovers, (j + 1), ft_strlen(leftovers));
				i = 0;
				res = ft_strdup(line);
				free(line);
				line = "";
				return (res);
			}
			else
				line[i++] = leftovers[j++];
		}
	}
	return (0); // pas sure de celui-ci.
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
