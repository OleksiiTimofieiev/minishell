/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simple_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:53:03 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:43 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_case_1(int *s, int *c)
{
	*s = (g_v.mfw - (ft_strlen(g_v.t.str) - (ft_strlen(g_v.t.str) - g_v.pr)));
	if (ft_strcmp(g_v.t.str, "") == 0)
		*s = g_v.mfw;
	else if (g_v.pr > (int)ft_strlen(g_v.t.str))
		*s = g_v.mfw - (g_v.pr - ft_strlen(g_v.t.str));
	*c = g_v.mfw - *s;
}

void	ft_case_2(int *s, int *c)
{
	if ((g_v.mfw > (int)ft_strlen(g_v.t.str)) && (g_v.k & F_PR))
		*s = g_v.mfw;
	else
		*s = (g_v.mfw - (ft_strlen(g_v.t.str) - g_v.pr));
	*c = g_v.mfw - *s;
}

void	ft_case_3(int *s)
{
	*s = 0;
	if (g_v.k & F_PR)
		;
	else
		g_v.quantity += write(1, g_v.t.str, ft_strlen(g_v.t.str));
}

void	ft_case_4(int *s, int *c)
{
	*s = (g_v.mfw == 0) ? 0 : g_v.mfw - ft_strlen(g_v.t.str) - g_v.pr;
	if (ft_strcmp(g_v.t.str, "") == 0)
	{
		*s = 0;
		*c = 0;
	}
	else if (g_v.mfw == 0 && g_v.pr > 0)
	{
		*c = g_v.pr;
		g_v.mfw = *c;
	}
	else if (g_v.mfw > 0 && g_v.pr > 0)
	{
		if (g_v.mfw > (int)ft_strlen(g_v.t.str))
			*s = g_v.mfw - ft_strlen(g_v.t.str);
		else
			g_v.mfw = g_v.pr;
	}
}

void	ft_print_simple(void)
{
	int		i;
	int		j;
	char	printable_character;
	int		s;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	printable_character = (g_v.k & F_Z) ? '0' : ' ';
	if ((g_v.mfw && g_v.pr) && (g_v.mfw > g_v.pr))
		ft_case_1(&s, &c);
	else if (g_v.mfw && g_v.pr == 0)
		ft_case_2(&s, &c);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		ft_case_3(&s);
	else if (g_v.pr > g_v.mfw)
		ft_case_4(&s, &c);
	printer_simple_string(&s, &c, printable_character);
}
