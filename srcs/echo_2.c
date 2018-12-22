/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:48:39 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 12:50:17 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		env_var_detection(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '$')
			i++;
		str++;
	}
	if (i >= 2)
		return (1);
	return (0);
}

int		spaces_quantity(char **arguments, int start_index)
{
	int result;

	result = 0;
	while (arguments[start_index])
	{
		result++;
		start_index++;
	}
	return (result);
}
