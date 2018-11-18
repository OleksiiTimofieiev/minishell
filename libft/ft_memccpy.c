/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:32:45 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;

	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		*(dst1 + i) = *(src1 + i);
		if (*(dst1 + i) == (unsigned char)c)
			return (dst1 + i + 1);
		i++;
	}
	return (NULL);
}
