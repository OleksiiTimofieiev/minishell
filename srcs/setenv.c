/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/01 11:57:06 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_index_envp(char **envp_finde, char *name)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp_finde[i])
	{
		if (ft_strncmp(envp_finde[i], name, len) == 0)
			return (i);
		i++;
	}
	return (0);
}

char	**get_buf_envp(char **arguments, char **envp_init)
{
	int		i;
	int		len;
	char	**buf;

	i = 0;
	len = len_char_2d_array(envp_init) + 2;
	buf = (char **)malloc(sizeof(char *) * (len));
	while (envp_init[i])
	{
		buf[i] = ft_strdup(envp_init[i]);
		i++;
	}
	buf[i] = ft_strdup(arguments[1]);
	ft_strcat(buf[i], "=");
	ft_strcat(buf[i++], arguments[2]);
	buf[i] = NULL;
	return (buf);
}

char	**envp_res_logic(char **arguments, char **envp_init, int i)
{
	char **envp_buf;

	if (ft_strequ(arguments[3], "1"))
	{
		envp_buf = copy_2d_char(envp_init);
		free(envp_buf[i]);
		envp_buf[i] = ft_strdup(arguments[1]);
		ft_strcat(envp_buf[i], "=");
		ft_strcat(envp_buf[i], arguments[2]);
	}
	else
		envp_buf = copy_2d_char(envp_init);
	return (envp_buf);
}

char	**setenv_minishell(char *str, char **envp_init)
{
	int		i;
	char	**arguments;
	char	**envp_res;

	envp_res = NULL;
	arguments = ft_strsplit(str, 32);
	if (len_char_2d_array(arguments) != 4)
	{
		ft_clean_2d_char(arguments);
		return (envp_init);
	}
	i = get_index_envp(envp_init, arguments[1]);
	if (i)
		envp_res = envp_res_logic(arguments, envp_init, i);
	else
		envp_res = get_buf_envp(arguments, envp_init);
	ft_clean_2d_char(arguments);
	ft_clean_2d_char(envp_init);
	return (envp_res);
}
