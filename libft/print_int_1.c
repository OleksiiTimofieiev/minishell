/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:33:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:09 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_1_int(int *s, int *d, int *z, ssize_t g)
{
	int i;

	i = (g_v.k & F_P || g_v.k & F_S) ? 1 : 0;
	*s = g_v.mfw - g_v.pr - i;
	*z = g_v.pr - ft_decimal_length(g);
	*d = ft_decimal_length(g);
	if (ft_decimal_length(g) >= g_v.pr)
		*s = g_v.mfw - ft_decimal_length(g) - i;
	else if (g_v.k & F_S)
		g_v.quantity += write(1, " ", 1);
	else if (g_v.k & F_Z && !(g >= 0))
		*s -= 1;
	if (g < 0 && !(g_v.k & F_Z) && !(g_v.k & F_M) && !(g_v.k & F_P))
		*s -= 1;
}

void	case_2_helper(int **s, int **z, ssize_t g)
{
	if (g_v.k & F_S && g > 0 && g_v.k & F_Z)
	{
		g_v.quantity += write(1, " ", 1);
		**z = g_v.mfw - ft_decimal_length(g) - 1;
	}
	if (g_v.pr == 0 && g_v.mfw > 0 && g_v.t.pul == 0
	&& !(g_v.k & F_P) && !(g_v.k & S_Z))
	{
		**s = g_v.mfw;
		if (g_v.k & F_S && g_v.k & F_Z)
		{
			**s = g_v.mfw - 2;
			**z = 1;
		}
	}
}

void	case_2_int(int *s, int *d, int *z, ssize_t g)
{
	int i;

	i = ((g_v.k & F_M && g < 0) || g_v.k & F_P || g < 0) ? 1 : 0;
	*s = g_v.mfw - ft_decimal_length(g) - i;
	*z = 0;
	*d = ft_decimal_length(g);
	if (g_v.k & F_Z)
	{
		*s = 0;
		*z = g_v.mfw - ft_decimal_length(g) - i;
	}
	else if (g_v.k & F_S && g_v.k & F_M && g > 0)
	{
		g_v.quantity += write(1, " ", 1);
		*s = g_v.mfw - ft_decimal_length(g) - 1;
	}
	case_2_helper(&s, &z, g);
}

void	case_3_int(int *s, int *z, ssize_t g)
{
	if (g_v.k & S_L || g_v.k & S_LL || g_v.k & S_HH
	|| g_v.k & S_HH || g_v.k & S_J || g_v.k & S_Z)
		*z = 0;
	*s = 0;
	*z = 0;
	if (g_v.k & F_S && g > 0)
		g_v.quantity += write(1, " ", 1);
}

void	case_4_int(int *s, int *d, int *z, ssize_t g)
{
	*s = 0;
	*z = g_v.pr - ft_decimal_length(g);
	*d = ft_decimal_length(g);
	if (g_v.k & F_S)
		g_v.quantity += write(1, " ", 1);
	if (g_v.pr > 0 && g_v.k & F_WILD)
		*z = 0;
	if (g_v.pr > 0 && g_v.mfw > 0 && g_v.k & F_WILD && g_v.k & F_Z)
		*z = g_v.mfw - ft_decimal_length(g);
	if (g == 0 && g_v.k & F_WILD)
		*z = g_v.pr;
}
