/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:15:45 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:38 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_size_mod(void)
{
	while (*g_v.p)
	{
		if (*g_v.p == 'h' && *(g_v.p + 1) == 'h')
		{
			g_v.k |= S_HH;
			g_v.p += 2;
		}
		else if (*g_v.p == 'l' && *(g_v.p + 1) == 'l')
		{
			g_v.k |= S_LL;
			g_v.p += 2;
		}
		else if (ft_check_size_mod())
		{
			ft_set_size_mod();
			g_v.p++;
		}
		else
			break ;
	}
}

void	ft_empty_specifier_handler(void)
{
	int		i;
	char	printable_character;

	i = 0;
	g_v.t.letter = *g_v.p;
	g_v.p++;
	printable_character = (g_v.k & F_Z) ? '0' : ' ';
	if (!(g_v.k & F_DOT))
	{
		if (g_v.k & F_M)
		{
			g_v.quantity += write(1, &g_v.t.letter, 1);
			while (i++ < (g_v.mfw - 1))
				g_v.quantity += write(1, &printable_character, 1);
		}
		else
		{
			while (i++ < (g_v.mfw - 1))
				g_v.quantity += write(1, &printable_character, 1);
			g_v.quantity += write(1, &g_v.t.letter, 1);
		}
	}
	else
		g_v.quantity += write(1, &g_v.t.letter, 1);
}

void	ft_get_conversions(void)
{
	while (*g_v.p)
	{
		if (ft_check_conversions())
		{
			ft_set_conversions();
			g_v.p++;
			break ;
		}
		else
			ft_empty_specifier_handler();
		break ;
	}
}

void	ft_get_min_field_width(void)
{
	int i;
	int tmp;

	i = 0;
	if (!(g_v.k & F_WILD))
		g_v.mfw = ft_atoi(g_v.p);
	if (g_v.mfw == 0)
		i = 0;
	else
	{
		tmp = g_v.mfw;
		if (g_v.mfw < 0)
			g_v.mfw *= -1;
		while (tmp > 0)
		{
			tmp /= 10;
			i++;
		}
	}
	if (!(g_v.k & F_WILD))
		g_v.p += i;
}

void	handle_star(int *i, va_list ap, int tmp)
{
	if (*g_v.p == '0')
	{
		g_v.k |= F_DOT;
		(*i)++;
	}
	if (*g_v.p == '*')
	{
		g_v.pr = va_arg(ap, int);
		if (g_v.pr < 0)
		{
			g_v.pr *= -1;
			g_v.k |= F_WILD;
		}
		(*i)++;
	}
	else
	{
		g_v.pr = ft_atoi(g_v.p);
		tmp = g_v.pr;
		while (tmp > 0)
		{
			tmp /= 10;
			(*i)++;
		}
	}
}
