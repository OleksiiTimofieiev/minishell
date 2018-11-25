/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/25 16:21:49 by otimofie         ###   ########.fr       */
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

char	**get_buf_envp(char **arguments, char **envp)
{
	int i;
	int len;
	char **buf;

	i = 0;
	len = len_char_2d_array(envp);
	buf = (char **)malloc(sizeof(char *) * (len + 2));
	while(envp[i])
	{
		buf[i] = ft_strdup(envp[i]);
		i++;
	}
	buf[i] = ft_strdup(arguments[1]);
	ft_strcat(buf[i], "=");
	ft_strcat(buf[i], arguments[2]);
	ft_printf("argument->%s\n", buf[i]);
	buf[len + 1] = NULL;
	return (buf);
}

void	realloc_envp(char **envp, char **buf)
{
	int i;
	int len;

	i = 0;
	len = len_char_2d_array(envp) + 1;
	envp = (char **)malloc(sizeof(char *) * len);

	while(buf[i])
	{
		envp[i] = ft_strdup(buf[i]);
		i++;
	}
	envp[i] = NULL;
}

int		setenv_minishell(char *str, char **envp)
{

	int i;
	char **arguments;
	int	len;
	char **envp_buf;

	arguments = ft_strsplit(str, 32);
	len = len_char_2d_array(arguments);

	if (len < 4 || len > 4)
	{
		ft_clean_2d_char(arguments);

		return (0);
	}

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
		envp_buf = get_buf_envp(arguments, envp);
		ft_clean_2d_char(envp);
		realloc_envp(envp, envp_buf);
		ft_clean_2d_char(envp_buf);
	}
	ft_clean_2d_char(arguments);

	return (0);
}