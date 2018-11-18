/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:21:24 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/11 15:21:26 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t length;

	i = 0;
	j = 0;
	length = ft_strlen(needle);
	if (length == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j] && (i + j) < len)
		{
			if (j == length - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
