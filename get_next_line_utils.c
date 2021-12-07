/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:57:35 by nchennaf          #+#    #+#             */
/*   Updated: 2021/12/07 20:49:47 by nchennaf         ###   ########.fr       */
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

int	line_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_src;
	char	*ptr_dst;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (ptr_dst > ptr_src)
	{
		while (len-- > 0)
			ptr_dst[len] = ptr_src[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	return (ptr_dst);
}

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	size_t			s_len;

	if (s == NULL)
		return (NULL);
	s_len = (size_t)ft_strlen((char *)s);
	i = 0;
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (i < len && (s[start + i]))
	{
		ptr[i] = (char)s[start + i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}*/
