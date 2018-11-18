/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:50:08 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:44 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_derivative_conversions(void)
{
	if (*g_v.p == 'D')
	{
		g_v.k |= C_DECIMAL;
		g_v.k |= S_L;
	}
	if (*g_v.p == 'O')
	{
		g_v.k |= C_OCTAL;
		g_v.k |= S_L;
	}
	if (*g_v.p == 'U')
	{
		g_v.k |= C_U;
		g_v.k |= S_L;
	}
	if (*g_v.p == 'p')
	{
		g_v.k |= C_P;
		g_v.k |= F_H;
		g_v.k |= S_L;
	}
}

void	ft_set_conversions(void)
{
	(*g_v.p == 'c') ? g_v.k |= C_SYMBOL : 0;
	(*g_v.p == 'd' || *g_v.p == 'i') ? g_v.k |= C_DECIMAL : 0;
	(*g_v.p == 's') ? g_v.k |= C_STRING : 0;
	(*g_v.p == 'C') ? g_v.k |= C_MC : 0;
	(*g_v.p == 'S') ? g_v.k |= C_MS : 0;
	(*g_v.p == 'x') ? g_v.k |= C_HEX : 0;
	(*g_v.p == 'X') ? g_v.k |= C_HEXBIG : 0;
	(*g_v.p == 'o') ? g_v.k |= C_OCTAL : 0;
	(*g_v.p == 'u') ? g_v.k |= C_U : 0;
	ft_derivative_conversions();
}

void	ft_set_flags(void)
{
	(*g_v.p == '-') ? g_v.k |= F_M : 0;
	(*g_v.p == '0') ? g_v.k |= F_Z : 0;
	(*g_v.p == '+') ? g_v.k |= F_P : 0;
	(*g_v.p == '#') ? g_v.k |= F_H : 0;
	(*g_v.p == ' ') ? g_v.k |= F_S : 0;
}

void	ft_get_flags(va_list ap)
{
	g_v.k = 0x0;
	while (*g_v.p)
	{
		if (*g_v.p == '*')
		{
			g_v.mfw = (int)va_arg(ap, int);
			(g_v.mfw < 0) ? g_v.k |= F_M : 0;
			g_v.k |= F_WILD;
			g_v.p++;
		}
		else if (ft_check_flags())
		{
			ft_set_flags();
			g_v.p++;
		}
		else
			break ;
	}
}
