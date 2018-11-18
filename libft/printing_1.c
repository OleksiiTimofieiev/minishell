/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:20:00 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:21:26 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wide_strlen(wchar_t *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

int		ft_byte_size(unsigned int value)
{
	int size;

	size = 0;
	size = ft_size_bin(value);
	if (size <= 7)
		size = 1;
	else if (size <= 11)
		size = 2;
	else if (size <= 16)
		size = 3;
	else
		size = 4;
	return (size);
}

int		ft_wide_strlen_bytes(wchar_t *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len = len + ft_byte_size(g_v.t.wstr[i]);
		i++;
	}
	return (len);
}

void	ft_wide_s_print(t_p g_v, int c)
{
	int i;

	i = 0;
	while (i < c)
		ft_wchar_print(g_v.t.wstr[i++]);
}
