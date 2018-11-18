/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:31:14 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:24:58 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	char_hendler_helper(void)
{
	int i;

	i = 0;
	if (g_v.k & F_M)
	{
		while (i++ < (g_v.mfw - 1))
			g_v.quantity += write(1, " ", 1);
	}
}

void	ft_char_handler(int x)
{
	int		i;
	char	printable_character;

	i = 0;
	g_v.t.letter = x;
	printable_character = (g_v.k & F_Z) ? '0' : ' ';
	if (g_v.mfw && (g_v.k & F_Z))
	{
		while (i++ < (g_v.mfw - 1))
			g_v.quantity += write(1, "0", 1);
	}
	else if (g_v.mfw && !(g_v.k & F_M))
	{
		while (i++ < (g_v.mfw - 1))
			g_v.quantity += write(1, " ", 1);
	}
	if (g_v.k & C_SYMBOL && g_v.k & S_L)
		ft_wchar_print(x);
	else
		g_v.quantity += write(1, &g_v.t.letter, 1);
	char_hendler_helper();
	(g_v.k & C_MC) ? ft_wchar_print(x) : 0;
}

void	ft_mc_handler(int x)
{
	int		i;
	char	printable_character;

	i = 0;
	g_v.t.letter = x;
	printable_character = (g_v.k & F_Z) ? '0' : ' ';
	if (g_v.mfw && (g_v.k & F_Z))
	{
		while (i++ < (g_v.mfw - 1))
			ft_putchar('0');
	}
	(g_v.k & C_MC) ? ft_wchar_print(x) : 0;
}

void	ft_str_handler(va_list ap)
{
	int i;

	g_v.t.str = va_arg(ap, char *);
	if (!g_v.t.str)
	{
		i = 0;
		if (g_v.t.str == NULL && g_v.mfw > 0 && !(g_v.k & F_WILD))
		{
			while (i++ <= g_v.mfw - 1)
				g_v.quantity += write(1, "0", 1);
		}
		else if (g_v.t.str == NULL)
		{
			g_v.quantity += write(1, "(null)", 6);
			return ;
		}
	}
	else
		(g_v.k & S_L) ? ft_print_w(g_v) : ft_print_simple();
}

void	ft_megastr_handler(va_list ap)
{
	int i;

	g_v.t.wstr = va_arg(ap, wchar_t *);
	if (g_v.t.wstr == NULL)
	{
		i = 0;
		if (g_v.t.wstr == NULL && g_v.mfw == 0)
		{
			g_v.quantity += write(1, "(null)", 6);
			return ;
		}
	}
	else
		ft_print_w_s();
}
