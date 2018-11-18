/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_w_s_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:15:00 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:30 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_w_s(void)
{
	int		i;
	int		j;
	char	p;
	int		s;
	int		c;

	i = 0;
	j = 0;
	c = 0;
	s = 0;
	p = (g_v.k & F_Z) ? '0' : ' ';
	if ((g_v.mfw && g_v.pr) && (g_v.mfw > g_v.pr))
		case_1_w(&s, &c);
	else if (g_v.mfw > 0 && g_v.pr == 0)
		case_2_w(&s, &c);
	else if (g_v.pr == 0 && g_v.mfw == 0)
	{
		s = 0;
		c = ft_wide_strlen(g_v.t.wstr);
	}
	else if (g_v.pr > g_v.mfw)
		case_4_w(&s, &c);
	print_w_str(c, s, p);
}
