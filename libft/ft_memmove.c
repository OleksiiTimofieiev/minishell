/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:43:22 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/05 16:43:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *src1;
	char *dst1;

	src1 = (char *)src;
	dst1 = (char *)dst;
	if (src1 < dst1)
	{
		while (len--)
			dst1[len] = src1[len];
	}
	else
		ft_memcpy(dst1, src1, len);
	return (dst1);
}
