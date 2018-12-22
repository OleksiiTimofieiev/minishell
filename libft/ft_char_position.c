/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:59:05 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 13:59:32 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_position(char *str, char c)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
	}
	return (i);
}
