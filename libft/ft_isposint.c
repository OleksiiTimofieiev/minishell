/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isposint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 13:33:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/04/22 13:39:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	ft_atoi_here(const char *str)
{
	ssize_t	i;
	ssize_t	res;
	ssize_t	mark;

	i = 0;
	res = 0;
	mark = 1;
	while ((str[i] >= 9 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		mark = str[i] == '-' ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > res * 10 + (str[i] - '0'))
			return (mark == 1 ? -1 : 0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * mark);
}

int				ft_isposint(char *str)
{
	int i;
	int len;

	i = 0;
	len = (int)(ft_strlen(str));
	if (ft_atoi(&str[0]) <= 0)
		return (0);
	else if (!ft_strlen(str) || ft_strlen(str) < 1 || ft_strlen(str) > 10)
		return (0);
	while (i < len)
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	if (!ft_isint(ft_atoi_here(str)))
		return (0);
	return (1);
}
