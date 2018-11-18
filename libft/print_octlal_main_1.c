/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octlal_main_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 13:06:17 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:53 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_1_octal_main(int *s, int *d, int *z, size_t g)
{
	int i;

	i = 0;
	i = (g_v.k & F_M || g_v.k & F_P) ? 1 : 0;
	i = (g_v.k & F_H) ? 2 : 0;
	*s = g_v.mfw - g_v.pr - i;
	if (ft_octal_length(g) > g_v.pr)
		*s = g_v.mfw - ft_octal_length(g) - i;
	else if (ft_octal_length(g) < g_v.mfw)
		*s = g_v.mfw - g_v.pr;
	*z = g_v.pr - ft_octal_length(g);
	*d = ft_octal_length(g);
}

void	case_2_octal_main(int *s, int *d, int *z, size_t g)
{
	int i;

	i = 0;
	i = (g_v.k & F_H) ? 1 : 0;
	*s = g_v.mfw - ft_octal_length(g) - i;
	*z = 0;
	if (g_v.k & F_Z && g_v.k & F_M)
	{
		*s = g_v.mfw - ft_octal_length(g) - i;
		*z = 0;
	}
	else if (g_v.k & F_Z)
	{
		*z = g_v.mfw - ft_octal_length(g) - i;
		*s = 0;
		if (g_v.k & F_H)
			*z = g_v.mfw - ft_octal_length(g) - 1;
	}
	else if (g_v.k & F_M && g_v.k & F_H)
		*s = g_v.mfw - ft_octal_length(g_v.t.pul2) - 1;
	*d = ft_octal_length(g);
}

void	case_3_octal_main(int *s, int *d, int *z, size_t g)
{
	*z = 0;
	if (g_v.k & S_L || g_v.k & S_LL || g_v.k & S_HH
	|| g_v.k & S_HH || g_v.k & S_J || g_v.k & S_Z)
	{
		*z = 0;
	}
	*s = 0;
	*d = ft_octal_length(g);
}

void	case_4_octal_main(int *s, int *d, int *z, size_t g)
{
	*s = 0;
	*z = g_v.pr - ft_octal_length(g);
	*d = ft_octal_length(g);
	if (g_v.k & F_H)
		*z = g_v.pr - ft_octal_length(g) - 1;
}
