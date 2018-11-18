/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:21:35 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/11 15:21:43 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int length;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	j = 0;
	length = ft_strlen(needle);
	while (haystack[i])
	{
		while (needle[j] == haystack[i + j])
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
