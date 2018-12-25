/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:10:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 14:10:35 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tilda_fork(char **arguments)
{
	char	*result;
	int		i;

	i = 0;
	while (arguments[i])
	{
		if (arguments[i][0] == '~' && arguments[i][1] == '/')
		{
			result = ft_strnew(ft_strlen("/Users/otimofie")
				+ ft_strlen(&arguments[i][1]));
			ft_strcat(result, "/Users/otimofie");
			ft_strcat(result, &arguments[i][1]);
			free(arguments[i]);
			arguments[i] = ft_strdup(result);
			free(result);
		}
		i++;
	}
}
