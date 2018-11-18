/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:31:25 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/04 19:31:27 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*src1;
	char	*dst1;

	src1 = (char*)src;
	dst1 = (char*)dst;
	i = 0;
	while (n-- > 0)
	{
		*(dst1 + i) = *(src1 + i);
		i++;
	}
	return (dst1);
}
