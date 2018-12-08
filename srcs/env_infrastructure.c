/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_infrastructure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:52:03 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 18:16:19 by otimofie         ###   ########.fr       */
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

int detect_del_var_cd_del(char *env, char **haystack)
{
	int i;
	int len_of_env;

	i = 0;
	len_of_env = ft_strlen(env);
	while (haystack[i])
	{
		if (ft_strncmp(env, haystack[i], len_of_env) == 0) //
			return (i);
		i++;
	}
	return (0);
}

void	ft_clean(char **envp)
{
	int path[2];

	path[0] = detect_del_var_cd_del("PWD", envp);
	path[1] = detect_del_var_cd_del("OLDPWD", envp);

	if (envp[path[0]])
		free(envp[path[0]]);
	if (envp[path[1]])
		free(envp[path[1]]);
}

char	**init_envp_buf(char **envp)
{
	int		i;
	int		len;
	char	**envp_buf;

	i = 0;
	len = len_char_2d_array(envp) + 1;
	envp_buf = (char **)malloc(sizeof(char *) * (len));
	while (envp[i])
	{
		envp_buf[i] = ft_strdup(envp[i]);
		i++;
	}
	envp_buf[i] = NULL;
	return (envp_buf);
}
