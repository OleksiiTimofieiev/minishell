/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_u_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:39:24 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:01 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_int_u(size_t g)
{
	int i;
	int j;
	int s;
	int d;
	int z;

	i = 0;
	j = 0;
	s = 0;
	d = 0;
	z = 0;
	if ((g_v.mfw != 0 && g_v.pr) && ((g_v.mfw > g_v.pr) || g_v.mfw < 0))
		case_1_u(&s, &d, &z, g);
	else if (g_v.mfw && g_v.pr == 0)
		case_2_u(&s, &d, &z, g);
	else if (g_v.pr == 0 && g_v.mfw == 0)
		case_3_u(&s, &z);
	else if (g_v.pr > g_v.mfw)
		case_4_u(&s, &d, &z, g);
	i = 0;
	j = 0;
	printer_u(s, &i, z, g);
}
