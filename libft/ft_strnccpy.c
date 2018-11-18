/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:27:10 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/27 14:27:15 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(char *src, char c)
{
	int count;

	if (!src)
		return (0);
	count = 0;
	while (*src != c)
	{
		count++;
		src++;
	}
	return (count);
}

char		*ft_strnccpy(char *src, char c)
{
	size_t	i;
	char	*dst;
	size_t	len;

	i = 0;
	len = ft_size(src, c);
	if (!(dst = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
