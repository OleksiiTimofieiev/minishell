/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:20:36 by otimofie          #+#    #+#             */
/*   Updated: 2018/02/21 13:20:38 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex_big(size_t n, size_t limit)
{
	size_t i;

	i = 0;
	if (n >= 16 && i < limit)
		ft_print_hex_big(n / 16, limit);
	if (n % 16 < 10 && i < limit)
	{
		ft_putchar((n % 16) + 48);
		i++;
	}
	else
	{
		ft_putchar((n % 16) - 10 + 65);
		i++;
	}
}
