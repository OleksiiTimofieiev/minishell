/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:26:11 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/18 13:26:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_s_int(long long nb)
{
	int	lol;

	lol = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		lol++;
	}
	return (lol);
}

char				*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			neg_checker;
	long long	n1;

	n1 = n;
	neg_checker = (n >= 0) ? 0 : 1;
	n1 = (n >= 0) ? n1 : -n1;
	len = (n >= 0) ? ft_s_int(n1) : ft_s_int(n1) + 1;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	str[len] = '\0';
	while (len-- > neg_checker)
	{
		str[len] = n1 % 10 + '0';
		n1 /= 10;
	}
	return (str);
}
