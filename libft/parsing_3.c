/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:11:01 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:35 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_precision(va_list ap)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	if (*g_v.p == '.')
	{
		g_v.k |= F_PR;
		g_v.p++;
		handle_star(&i, ap, tmp);
	}
	else
		g_v.pr = 0;
	g_v.p += i;
}

void	ft_corrections(void)
{
	if (g_v.k & C_DECIMAL)
	{
		if (g_v.k & F_M && g_v.k & F_Z)
			g_v.k &= ~(F_Z);
		else if (g_v.k & F_S && g_v.k & F_P)
			g_v.k &= ~(F_S);
	}
}

void	ft_parsing(va_list ap)
{
	ft_get_flags(ap);
	ft_get_min_field_width();
	ft_get_precision(ap);
	ft_get_size_mod();
	ft_get_conversions();
	ft_corrections();
	ft_select_printing_conversion(ap);
}
