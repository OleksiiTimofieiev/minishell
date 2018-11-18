/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_main_pointer_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:10:54 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:23:49 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_1_pointer(int *s, int *d, int *z, size_t g)
{
	int i;

	i = ((g_v.k & F_M) || (g_v.k & F_P)) ? 1 : 0;
	i = (g_v.k & F_H) ? 2 : 0;
	*s = g_v.mfw - g_v.pr - i;
	if ((int)ft_hex_length(g) > g_v.pr)
		*s = g_v.mfw - ft_hex_length(g) - i;
	*z = g_v.pr - ft_hex_length(g);
	*d = ft_hex_length(g);
}

void	case_2_pointer(int *s, int *d, int *z, size_t g)
{
	*s = g_v.mfw - ft_hex_length(g);
	if (g_v.k & F_H)
		*s = g_v.mfw - ft_hex_length(g) - 2;
	*z = 0;
	if (g_v.k & F_Z && g_v.k & F_M && g_v.k & F_H)
	{
		*s = g_v.mfw - ft_hex_length(g) - 2;
		*z = 0;
	}
	else if (g_v.k & F_H && g_v.k & F_Z)
	{
		*z = g_v.mfw - ft_hex_length(g) - 2;
		*s = 0;
	}
	else if (g_v.k & F_Z)
	{
		*z = g_v.mfw - ft_hex_length(g);
		*s = 0;
	}
	*d = ft_hex_length(g);
}

void	case_3_pointer(int *s, int *d, int *z, size_t g)
{
	*z = 0;
	if (g_v.k & S_L || g_v.k & S_LL || g_v.k & S_HH
	|| g_v.k & S_HH || g_v.k & S_J || g_v.k & S_Z)
		*z = 0;
	*s = 0;
	*d = ft_hex_length(g);
}

void	case_4_pointer(int *s, int *z, size_t g)
{
	*s = 0;
	*z = g_v.pr - (int)ft_hex_length(g);
	if (g == 0)
	{
		g_v.quantity += write(1, "0x", 2);
		*z = g_v.pr - (int)ft_hex_length(g);
	}
}

void	case_5_pointer(void)
{
	int i;

	i = 0;
	while (i < g_v.mfw)
	{
		g_v.quantity += write(1, " ", 1);
		i++;
	}
}
