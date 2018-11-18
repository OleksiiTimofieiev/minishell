/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:28:00 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:19 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf_ss(ssize_t n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr_printf_ss(n / 10);
	g_v.quantity += 1;
	ft_putchar(n % 10 + '0');
}

void	ft_print_octal_2(size_t num, size_t limit)
{
	if (num && limit--)
	{
		ft_print_octal(num / 8, limit);
		ft_putchar((num % 8) + '0');
	}
}

void	ft_putnbr_printf_s(size_t n)
{
	if (n >= 10)
	{
		ft_putnbr_printf_s(n / 10);
		ft_putnbr_printf_s(n % 10);
	}
	else
	{
		g_v.quantity += 1;
		ft_putchar(n + '0');
	}
}

void	ft_print_hex_pr(size_t n, size_t limit)
{
	size_t	quotient;
	size_t	remainder;
	int		j;
	size_t	counter;
	char	hexadecimalnum[1000];

	j = 0;
	counter = 0;
	quotient = n;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	quotient = j;
	while (quotient > 0 && counter < limit)
	{
		g_v.quantity += write(1, &hexadecimalnum[--quotient], 1);
		counter++;
	}
}

void	ft_print_hex_big_2(size_t n, size_t limit)
{
	size_t	quotient;
	size_t	remainder;
	int		j;
	size_t	counter;
	char	hexadecimalnum[1000];

	j = 0;
	counter = 0;
	quotient = n;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	quotient = j;
	while (i >= 0 && counter < limit)
	{
		g_v.quantity += write(1, &hexadecimalnum[--quotient], 1);
		counter++;
	}
}
