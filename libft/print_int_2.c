/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:35:27 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:13 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_case_1(int s, int z, ssize_t g)
{
	int i;
	int j;

	i = 0;
	if (g_v.k & F_Z && g < 0)
		g_v.quantity += write(1, "-", 1);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
	if (!(g_v.k & F_Z) && g < 0)
		g_v.quantity += write(1, "-", 1);
	else if ((g_v.k & F_P) && (g >= 0))
		g_v.quantity += write(1, "+", 1);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	if ((g_v.k & F_DOT || g_v.k & F_PR) && g == 0 && !(g_v.k & F_Z))
		;
	else
		ft_putnbr_printf_ss(g);
}

void	print_case_2(int s, int z, ssize_t g)
{
	int i;
	int j;

	i = 0;
	if ((g_v.k & F_M) && (g < 0))
		g_v.quantity += write(1, "-", 1);
	if ((g_v.k & F_P) && (g > 0))
		g_v.quantity += write(1, "+", 1);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	ft_putnbr_printf_ss(g);
	if (g == 0)
		s -= 1;
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
}

void	ft_print_int(ssize_t g)
{
	int i;
	int j;
	int s;
	int d;
	int z;

	i = 0;
	j = 0;
	s = 0;
	d = 0;
	z = 0;
	if ((g_v.mfw != 0 && g_v.pr) && g_v.mfw > g_v.pr)
		case_1_int(&s, &d, &z, g);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_int(&s, &d, &z, g);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		case_3_int(&s, &z, g);
	else if (g_v.pr > g_v.mfw)
		case_4_int(&s, &d, &z, g);
	if (!(g_v.k & F_M))
		print_case_1(s, z, g);
	else
		print_case_2(s, z, g);
}
