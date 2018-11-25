/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_infrastructure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:52:03 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/25 12:54:15 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_global_var(char **envp, char *command)
{
	int		i;
	char	*buf;
	char	*result;

	buf = NULL;
	i = 0;
	result = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], &command[1], ft_strlen(&command[1])))
		{
			buf = ft_strdup(envp[i]);
			break ;
		}
		i++;
	}
	i = 0;
	if (buf)
	{
		while (buf[i] && buf[i] != '=')
			i++;
		result = ft_strdup(&buf[++i]);
		free(buf);
	}
	return (result);
}

void	ft_clean(char **envp)
{
	if (envp[6])
		free(envp[6]);
	if (envp[22])
		free(envp[22]);
}