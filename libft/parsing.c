/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 21:50:51 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:22:31 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_compare_chars_for_parser(char a, char b)
{
	if (a == b)
		return (1);
	else
		return (0);
}

int		ft_check_flags(void)
{
	char *flags;

	flags = "-0+ #";
	while (*flags != '\0')
	{
		if (ft_compare_chars_for_parser(*g_v.p, *flags))
			return (1);
		flags++;
	}
	return (0);
}

int		ft_check_size_mod(void)
{
	char			*size_mod;
	enum e_size_mod	valid;

	size_mod = "hljz";
	valid = h;
	while (valid <= z)
	{
		if (ft_compare_chars_for_parser(*g_v.p, size_mod[valid]))
			return (1);
		valid++;
	}
	return (0);
}

int		ft_check_conversions(void)
{
	char				*valid_conversions;
	enum e_conversions	valid;

	valid_conversions = "dxiDcsCSXoOuUp";
	valid = d;
	while (valid <= p)
	{
		if (ft_compare_chars_for_parser(*g_v.p, valid_conversions[valid]))
			return (1);
		valid++;
	}
	return (0);
}

void	ft_set_size_mod(void)
{
	(*g_v.p == 'l') ? g_v.k |= S_L : 0;
	(*g_v.p == 'j') ? g_v.k |= S_J : 0;
	(*g_v.p == 'h') ? g_v.k |= S_H : 0;
	(*g_v.p == 'z') ? g_v.k |= S_Z : 0;
}
