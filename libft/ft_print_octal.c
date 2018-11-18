/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 11:46:43 by otimofie          #+#    #+#             */
/*   Updated: 2018/02/23 11:46:45 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_octal(size_t num, size_t limit)
{
	if (num && limit--)
	{
		ft_print_octal(num / 8, limit);
		ft_putchar((num % 8) + '0');
	}
}
