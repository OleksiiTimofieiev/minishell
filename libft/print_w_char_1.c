/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w_char_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:42:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:39 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_1_w_c(int *s, int *c)
{
	int i;

	i = 0;
	*c = 0;
	*s = 0;
	while (g_v.pr >= 0)
	{
		*c = *c + (g_v.pr / ft_byte_size(g_v.t.wstr[i]));
		g_v.pr -= *c * ft_byte_size(g_v.t.wstr[i]);
		i++;
	}
	*s = g_v.mfw - *c * ft_byte_size(g_v.t.wstr[i]);
}

void	case_2_w_c(int *s, int *c)
{
	if (g_v.mfw < ft_wide_strlen(g_v.t.wstr))
		*s = 0;
	*c = ft_wide_strlen(g_v.t.wstr);
}

void	case_4_w_c(int *s, int *c)
{
	int i;

	i = 0;
	*c = 0;
	*s = 0;
	while (g_v.pr >= 0)
	{
		*c = *c + (g_v.pr / ft_byte_size(g_v.t.wstr[i]));
		g_v.pr -= *c * ft_byte_size(g_v.t.wstr[i]);
		i++;
	}
	*s = g_v.mfw - *c * ft_byte_size(g_v.t.wstr[i]);
}

void	wchar_printer(char p, int s, int c, t_p g_v)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_v.k & F_M)
	{
		while (i++ < c)
			ft_wchar_print(g_v.t.wstr[j++]);
		while (i++ <= g_v.mfw)
			ft_putchar(p);
	}
	else
	{
		if (!(g_v.k & C_MS))
		{
			while (i++ < s)
				ft_putchar(p);
			ft_wide_s_print(g_v, c);
		}
	}
}

void	ft_print_w(t_p g_v)
{
	int		i;
	int		j;
	char	p;
	int		s;
	int		c;

	i = 0;
	j = 0;
	p = 0;
	s = 0;
	c = 0;
	p = (g_v.k & F_Z) ? '0' : ' ';
	if ((g_v.mfw && g_v.pr) && (g_v.mfw > g_v.pr))
		case_1_w_c(&s, &c);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_w_c(&s, &c);
	else if (g_v.pr == 0 && g_v.mfw == 0)
	{
		s = 0;
		c = ft_wide_strlen(g_v.t.wstr);
	}
	else if (g_v.pr > g_v.mfw)
		case_4_w_c(&s, &c);
	wchar_printer(p, s, c, g_v);
}
