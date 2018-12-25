/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_char_fork_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:04:09 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 14:06:55 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	special_char_fork(char **arguments, t_env *env)
{
	int		i;
	t_env	*env_local;

	i = 0;
	while (arguments[i])
	{
		if (arguments[i][0] == '$' &&
			special_char_occurance_fork(arguments[i]) == 1)
		{
			if (!find_char_fork(arguments[i], '/'))
			{
				env_local = find_elem(&env, &arguments[i][1]);
				if (env_local)
				{
					free(arguments[i]);
					arguments[i] = ft_strdup(env_local->content);
				}
			}
			else
			{
				special_char_help_fork(arguments, env);
			}
		}
		i++;
	}
}
