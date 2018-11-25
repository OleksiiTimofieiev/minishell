/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/25 15:53:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_index_envp(char **envp, char *name)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0)
			return (i);
		i++;
	}
	return (0);
}

int setenv_minishell(char *str, char **envp)
{
	// const char *name, const char *value, int overwrite,
	int i;
	char **arguments;

	arguments = ft_strsplit(str, 32);
	if (len_char_2d_array(arguments) < 3)
		return (0);
	

	i = get_index_envp(envp, arguments[1]);
	if (i)
	{
		if (ft_atoi(arguments[3]) == 1)
		{
			free(envp[i]);
			envp[i] = ft_strdup(arguments[1]);
			ft_strcat(envp[i], "=");
			ft_strcat(envp[i], arguments[2]);
			ft_printf("argument->%s\n", envp[i]);
		}
	}
	else
	{
		ft_printf("index not found -> %d\n", i);
	}
	return (0);
}