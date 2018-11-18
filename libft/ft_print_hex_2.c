/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:51:25 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:23:54 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	hex_printer_case_1(int s, int d, int z, size_t g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_v.k & F_H)
		g_v.quantity += write(1, "0x", 2);
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	ft_print_hex_pr(g, d);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
}

void	hex_printer_case_2(int s, int d, int z, size_t g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_v.k & F_H && z != 0)
		g_v.quantity += write(1, "0x", 2);
	while (i++ < s)
		g_v.quantity += write(1, " ", 1);
	j = 0;
	while (j++ < z)
		g_v.quantity += write(1, "0", 1);
	if (g_v.k & F_H && z == 0)
		g_v.quantity += write(1, "0x", 2);
	if (g_v.pr == 0 && g == 0)
		g_v.quantity += write(1, " ", 1);
	if (g == 0 && !(g_v.k & F_DOT) && g_v.pr > 0)
		g_v.quantity += write(1, "0", 1);
	if ((g_v.k & F_DOT || g_v.k & F_PR) && g == 0 && g_v.pr == 0)
		;
	else
		ft_print_hex_pr(g, d);
}

void	hex_printer(int s, int d, int z, size_t g)
{
	if (g_v.k & F_M)
		hex_printer_case_1(s, d, z, g);
	else if (!(g_v.k & F_M))
		hex_printer_case_2(s, d, z, g);
}

void	ft_print_hex_main(size_t g)
{
	int s;
	int d;
	int z;

	if ((g_v.mfw != 0 && g_v.pr) && ((g_v.mfw > g_v.pr) || g_v.mfw < 0))
		case_1_hex_main(&s, &d, &z, g);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_hex_main(&s, &d, &z, g);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		case_3_hex_main(&s, &d, &z, g);
	else if (g_v.pr > g_v.mfw)
		case_4_hex_main(&s, &d, &z, g);
	if (g == 0 && g_v.k & F_DOT && g_v.mfw > 0)
		case_5_hex_main();
	else if (g_v.mfw == 0 && g_v.t.pul2 == 0 && !(g_v.k & F_PR))
		g_v.quantity += write(1, "0", 1);
	else if (!(g_v.k & F_PR && g == 0 && g_v.mfw == 0))
		hex_printer(s, d, z, g);
}
