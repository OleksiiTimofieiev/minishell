/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:20:24 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/11 15:20:26 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			mark;

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
	return ((int)(res * mark));
}
