/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w_s_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:13:00 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:34 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_1_helper(int **c, int **s)
{
	int i;
	int bytes;

	i = 0;
	bytes = 0;
	while (g_v.pr > 0)
	{
		if (g_v.pr / ft_byte_size(g_v.t.wstr[i]))
		{
			**c = **c + (g_v.pr / ft_byte_size(g_v.t.wstr[i]));
			bytes += **c * ft_byte_size(g_v.t.wstr[i]);
		}
		g_v.pr -= bytes;
		i++;
	}
	**s = g_v.mfw - bytes;
}

void	case_1_w(int *s, int *c)
{
	int bytes;
	int i;

	bytes = 0;
	i = 0;
	if (g_v.mfw < g_v.pr)
	{
		while (g_v.pr >= 0)
		{
			*c = *c + (g_v.pr / ft_byte_size(g_v.t.wstr[i]));
			g_v.pr -= *c * ft_byte_size(g_v.t.wstr[i]);
			i++;
		}
		*s = g_v.mfw - *c;
	}
	else if (g_v.mfw > g_v.pr)
	{
		case_1_helper(&c, &s);
	}
}

void	case_2_w(int *s, int *c)
{
	if (g_v.mfw > 0 && g_v.pr == 0 && !(g_v.k & F_PR))
	{
		*s = g_v.mfw - ft_wide_strlen_bytes(g_v.t.wstr);
		*c = ft_wide_strlen(g_v.t.wstr);
		if (g_v.k & F_M)
			g_v.mfw = g_v.mfw - *s;
	}
	else
	{
		*c = 0;
		*s = g_v.mfw;
	}
}

void	case_4_w(int *s, int *c)
{
	int i;

	i = 0;
	while (g_v.pr >= 0)
	{
		*c = *c + (g_v.pr / ft_byte_size(g_v.t.wstr[i]));
		g_v.pr -= *c * ft_byte_size(g_v.t.wstr[i]);
		i++;
	}
	*s = g_v.mfw - *c * ft_byte_size(g_v.t.wstr[i]);
}

void	print_w_str(int c, int s, char p)
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
			g_v.quantity += write(1, &p, 1);
	}
	else
	{
		i = 0;
		while (i++ < s)
			g_v.quantity += write(1, &p, 1);
		ft_wide_s_print(g_v, c);
	}
}
