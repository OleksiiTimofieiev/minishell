/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timofieiev <timofieiev@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:31:25 by otimofie          #+#    #+#             */
/*   Updated: 2018/10/25 17:25:06 by timofieiev       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_decimal_length_u(size_t nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
