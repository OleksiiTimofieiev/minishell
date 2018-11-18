/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:58:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:25:35 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_1_byte(unsigned int value)
{
	unsigned char octet;

	octet = value;
	write(1, &octet, 1);
	g_v.quantity += 1;
}

void	ft_2_bytes(unsigned int v, unsigned int mask1)
{
	unsigned char octet;
	unsigned char o2;
	unsigned char o1;

	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
	g_v.quantity += 2;
}

void	ft_3_bytes(unsigned int v, unsigned int mask2)
{
	unsigned char octet;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
	g_v.quantity += 3;
}

void	ft_4_bytes(unsigned int v, unsigned int mask3)
{
	unsigned char octet;
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = (mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
	g_v.quantity += 4;
}

void	ft_wchar_print(unsigned int value)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	unsigned int	v;
	int				size;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	size = ft_size_bin(value);
	v = value;
	if (size <= 7)
		ft_1_byte(value);
	else if (size <= 11)
		ft_2_bytes(v, mask1);
	else if (size <= 16)
		ft_3_bytes(v, mask2);
	else
		ft_4_bytes(v, mask3);
}
