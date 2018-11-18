/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:04:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:25:02 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_the_var_according_to_a_flag_ss(va_list var)
{
	if (g_v.k & S_L)
		g_v.t.pul = (long int)va_arg(var, long int);
	else if (g_v.k & S_LL)
		g_v.t.pul = (long long int)va_arg(var, long long int);
	else if (g_v.k & S_J)
		g_v.t.pul = (intmax_t)va_arg(var, intmax_t);
	else if (g_v.k & S_Z)
		g_v.t.pul = (ssize_t)va_arg(var, ssize_t);
	else if (g_v.k & S_HH)
		g_v.t.pul = (signed char)va_arg(var, int);
	else if (g_v.k & S_H)
		g_v.t.pul = (short int)va_arg(var, int);
	else
		g_v.t.pul = (int)va_arg(var, int);
	if (g_v.t.pul < -9223372036854775807)
		g_v.quantity += write(1, "-9223372036854775808", 20);
	else
		ft_print_int(g_v.t.pul);
}

void	ft_get_the_var_according_to_a_flag_s(va_list var)
{
	if (g_v.k & S_L)
		g_v.t.pul2 = (unsigned long int)va_arg(var, unsigned long int);
	else if (g_v.k & S_LL)
		g_v.t.pul2 = (ULLI)va_arg(var, unsigned long long int);
	else if (g_v.k & S_J)
		g_v.t.pul2 = (uintmax_t)va_arg(var, uintmax_t);
	else if (g_v.k & S_Z)
		g_v.t.pul2 = (size_t)va_arg(var, size_t);
	else if (g_v.k & S_HH)
		g_v.t.pul2 = (unsigned char)va_arg(var, unsigned int);
	else if (g_v.k & S_H)
		g_v.t.pul2 = (unsigned short int)va_arg(var, unsigned int);
	else
		g_v.t.pul2 = (unsigned int)va_arg(var, unsigned int);
	(g_v.k & C_HEX) ? ft_print_hex_main(g_v.t.pul2) : 0;
	(g_v.k & C_HEXBIG) ? ft_print_hexbig(g_v.t.pul2) : 0;
	(g_v.k & C_OCTAL) ? ft_print_octal_main(g_v.t.pul2) : 0;
	(g_v.k & C_U) ? ft_print_int_u(g_v.t.pul2) : 0;
	(g_v.k & C_P) ? ft_print_hex_main_pointer(g_v.t.pul2) : 0;
}

void	ft_select_printing_conversion(va_list ap)
{
	(g_v.k & C_MC) ? ft_mc_handler(va_arg(ap, int)) : 0;
	(g_v.k & C_MS) ? ft_megastr_handler(ap) : 0;
	(g_v.k & C_SYMBOL) ? ft_char_handler(va_arg(ap, int)) : 0;
	(g_v.k & C_STRING) ? ft_str_handler(ap) : 0;
	(g_v.k & C_DECIMAL) ? ft_get_the_var_according_to_a_flag_ss(ap) : 0;
	(g_v.k & C_HEX) ? ft_get_the_var_according_to_a_flag_s(ap) : 0;
	(g_v.k & C_HEXBIG) ? ft_get_the_var_according_to_a_flag_s(ap) : 0;
	(g_v.k & C_OCTAL) ? ft_get_the_var_according_to_a_flag_s(ap) : 0;
	(g_v.k & C_U) ? ft_get_the_var_according_to_a_flag_s(ap) : 0;
	(g_v.k & C_P) ? ft_get_the_var_according_to_a_flag_s(ap) : 0;
}
