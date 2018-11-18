/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:03:19 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:23:25 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_current_n_chars(va_list ap)
{
	size_t *address;

	address = va_arg(ap, size_t *);
	*address = g_v.quantity;
	g_v.p++;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;

	g_v.quantity = 0;
	va_start(ap, format);
	g_v.p = (char *)format;
	while (*g_v.p != '\0')
	{
		if (*g_v.p == '%')
		{
			g_v.p++;
			if (*g_v.p == 'n')
				get_current_n_chars(ap);
			else if (*g_v.p == '%')
				g_v.quantity += write(1, &(*g_v.p++), 1);
			else
				ft_parsing(ap);
		}
		else
			g_v.quantity += write(1, &(*g_v.p++), 1);
	}
	va_end(ap);
	return (g_v.quantity);
}
