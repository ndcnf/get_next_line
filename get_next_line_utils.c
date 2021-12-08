/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:57:35 by nchennaf          #+#    #+#             */
/*   Updated: 2021/12/08 19:19:59 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = (char*)malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

int		line_len(char *s)
{
	static int	i; // oh yeah, on se souvient ou on en etait
	int			j; // le i du passe

	//i = 0; // inutile si static
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
		//j++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = (size_t)line_len((char *)s);
	i = 0;
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && (s[start + i]))
	{
		ptr[i] = (char)s[start + i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	size_t	i;
	size_t	len;

	i = 0;
	len = line_len((char *)s1);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

