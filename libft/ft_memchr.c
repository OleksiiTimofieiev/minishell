/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:58:07 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/05 17:58:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s1;

	s1 = (unsigned char*)s;
	while (n--)
	{
		if (*(s1) == (unsigned char)c)
			return (s1);
		s1++;
	}
	return (NULL);
}
