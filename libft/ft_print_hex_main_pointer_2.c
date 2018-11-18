/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_main_pointer_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:12:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:23:43 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_6_pointer(void)
{
	int i;

	i = 0;
	while (i < g_v.pr)
	{
		g_v.quantity += write(1, "0", 1);
		i++;
	}
}

void	case_1_main_printer(int s, int d, int z, size_t g)
{
	int i;
	int j;

	i = 0;
	if (g_v.k & F_H)
		g_v.quantity += write(1, "0x", 2);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	if (g_v.pr == 0 && g == 0)
		g_v.quantity += write(1, "0", 1);
	ft_print_hex_pr(g, d);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
}

void	case_2_main_printer(int s, int d, int z, size_t g)
{
	int i;
	int j;

	i = 0;
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
	if (g_v.k & F_H && z != 0)
		g_v.quantity += write(1, "0x", 2);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	if (g_v.k & F_H && z == 0)
		g_v.quantity += write(1, "0x", 2);
	if (g_v.pr == 0 && g == 0)
		g_v.quantity += write(1, "0", 1);
	if ((g_v.k & F_DOT || g_v.k & F_PR) && g == 0 && g_v.pr == 0)
		;
	else
		ft_print_hex_pr(g, d);
}

void	main_printer(int s, int d, int z, size_t g)
{
	if (g_v.k & F_M)
		case_1_main_printer(s, d, z, g);
	else if (!(g_v.k & F_M))
		case_2_main_printer(s, d, z, g);
}

void	ft_print_hex_main_pointer(size_t g)
{
	int s;
	int d;
	int z;

	if ((g_v.mfw && g_v.pr) && (g_v.mfw > g_v.pr))
		case_1_pointer(&s, &d, &z, g);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_pointer(&s, &d, &z, g);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		case_3_pointer(&s, &d, &z, g);
	else if (g_v.pr > g_v.mfw)
		case_4_pointer(&s, &z, g);
	if (g == 0 && g_v.k & F_DOT && g_v.mfw > 0)
		case_5_pointer();
	else if (g == 0 && g_v.pr == 0 && g_v.mfw == 0 && g_v.k & F_PR)
		g_v.quantity += write(1, "0x", 2);
	else if (g == 0 && g_v.pr != 0)
		case_6_pointer();
	else if (!(g_v.k & F_PR && g == 0 && g_v.mfw == 0))
		main_printer(s, d, z, g);
}
