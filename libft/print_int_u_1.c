/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_u_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:39:15 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:05 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_1_u(int *s, int *d, int *z, size_t g)
{
	int i;

	i = ((g_v.k & F_P) || g_v.k & F_S) ? 1 : 0;
	*s = g_v.mfw - g_v.pr - i;
	if (ft_decimal_length_u(g) > g_v.pr)
		*s = g_v.mfw - ft_decimal_length_u(g);
	*z = g_v.pr - ft_decimal_length_u(g);
	*d = ft_decimal_length_u(g);
	if (g_v.k & F_S)
		g_v.quantity += write(1, " ", 1);
}

void	case_2_u(int *s, int *d, int *z, size_t g)
{
	int i;

	i = (g_v.k & F_P) ? 1 : 0;
	*s = g_v.mfw - ft_decimal_length_u(g) - i;
	*z = 0;
	if (g_v.k & F_Z)
	{
		*s = 0;
		*z = g_v.mfw - ft_decimal_length_u(g) - i;
	}
	*d = ft_decimal_length_u(g);
	if (g_v.k & F_S && g_v.k & F_M && g > 0)
	{
		g_v.quantity += write(1, " ", 1);
		*s = g_v.mfw - ft_decimal_length_u(g) - 1;
	}
	if (g_v.k & F_S && g > 0 && g_v.k & F_Z)
	{
		g_v.quantity += write(1, " ", 1);
		*z = g_v.mfw - ft_decimal_length_u(g) - 1;
	}
	if (g_v.pr == 0 && g_v.mfw > 0 && g_v.t.pul == 0
	&& !(g_v.k & F_P) && !(g_v.k & S_Z))
		*s = g_v.mfw;
}

void	case_3_u(int *s, int *z)
{
	if (g_v.k & S_L || g_v.k & S_LL || g_v.k & S_HH
	|| g_v.k & S_HH || g_v.k & S_J || g_v.k & S_Z)
		*z = 0;
	*s = 0;
	*z = 0;
}

void	case_4_u(int *s, int *d, int *z, size_t g)
{
	*s = 0;
	*z = g_v.pr - ft_decimal_length_u(g);
	*d = ft_decimal_length_u(g);
	if (g_v.k & F_S)
		g_v.quantity += write(1, " ", 1);
}

void	printer_u(int s, int *i, int z, size_t g)
{
	if (!(g_v.k & F_M))
	{
		while ((*i)++ < s)
			g_v.quantity += write(1, " ", 1);
		*i = 0;
		while ((*i)++ < z)
			g_v.quantity += write(1, "0", 1);
		if (g_v.pr == 0 && g_v.mfw == 0 && g == 0 && g_v.k & F_PR)
			;
		else
			ft_putnbr_printf_s(g);
	}
	else
	{
		if (g_v.k & F_P)
			g_v.quantity += write(1, "+", 1);
		*i = 0;
		while ((*i)++ < z)
			g_v.quantity += write(1, "0", 1);
		ft_putnbr_printf_s(g);
		*i = 0;
		while ((*i)++ < s)
			g_v.quantity += write(1, " ", 1);
	}
}
