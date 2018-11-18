/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal_main_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:36:44 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:57 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printer_octal_1(int s, int d, int z, size_t g)
{
	int i;
	int j;

	i = 0;
	if (g_v.k & F_H)
		g_v.quantity += write(1, "0", 1);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	ft_print_octal_2(g, d);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
}

void	printer_octal_2(int s, int d, int z, size_t g)
{
	int i;
	int j;

	i = 0;
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	if (g_v.k & F_H)
		g_v.quantity += write(1, "0", 1);
	if (g_v.mfw == 0 && g_v.pr == 0 && g == 0
	&& !(g_v.k & F_H) && !(g_v.k & F_PR))
		g_v.quantity += write(1, "0", 1);
	ft_print_octal_2(g, d);
}

void	prnter_octal(int s, int d, int z, size_t g)
{
	if (g_v.k & F_M)
		printer_octal_1(s, d, z, g);
	else if (!(g_v.k & F_M))
		printer_octal_2(s, d, z, g);
}

void	ft_print_octal_main(size_t g)
{
	int s;
	int d;
	int z;

	s = 0;
	d = 0;
	z = 0;
	if (g_v.mfw != 0 && g_v.pr > 0 && g_v.mfw > g_v.pr)
		case_1_octal_main(&s, &d, &z, g);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_octal_main(&s, &d, &z, g);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		case_3_octal_main(&s, &d, &z, g);
	else if (g_v.pr > g_v.mfw)
		case_4_octal_main(&s, &d, &z, g);
	prnter_octal(s, d, z, g);
	g_v.quantity += d;
}
