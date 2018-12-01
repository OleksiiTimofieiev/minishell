/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:56:53 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/01 11:57:21 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_2d_char(char **src)
{
	int i;
	int len;
	char **res;

	i = 0;
	len = len_char_2d_array(src) + 1;
	res = (char **)malloc(sizeof(char *) * len);
	res[len] = NULL;
	while (src[i])
	{
		res[i] = ft_strdup(src[i]);
		i++;
	}
	return (res);
}
