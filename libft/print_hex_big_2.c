/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_big_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:42:15 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:26 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_case_1_hex(int z, int s, int d, size_t g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_v.k & F_H)
		g_v.quantity += write(1, "0X", 2);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	ft_print_hex_big_2(g, d);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
}

void	print_case_2_hex(int z, int s, int d, size_t g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_v.k & F_H && z != 0)
		g_v.quantity += write(1, "0X", 2);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	if (g_v.k & F_H && z == 0)
		g_v.quantity += write(1, "0X", 2);
	ft_print_hex_big_2(g, d);
}

void	printer_hexbig(int z, int s, int d, size_t g)
{
	if (g_v.k & F_M)
		print_case_1_hex(z, s, d, g);
	else if (!(g_v.k & F_M))
		print_case_2_hex(z, s, d, g);
}

void	ft_print_hexbig(size_t g)
{
	int s;
	int d;
	int z;

	s = 0;
	d = 0;
	z = 0;
	if ((g_v.mfw != 0 && g_v.pr) && ((g_v.mfw > g_v.pr) || g_v.mfw < 0))
		case_1_hexbig(&s, &z, &d, g);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_hexbig(&s, &z, &d, g);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		case_3_hexbig(&s, &z, &d, g);
	else if (g_v.pr > g_v.mfw)
		case_4_hexbig(&s, &z, &d, g);
	if (g == 0 && g_v.k & F_DOT)
		printer_helper_1();
	else if (g_v.mfw == 0 && g_v.t.pul2 == 0 && !(g_v.k & F_PR))
		g_v.quantity += write(1, "0", 1);
	else if (!(g_v.k & F_PR && g == 0 && g_v.mfw == 0))
		printer_hexbig(z, s, d, g);
}
