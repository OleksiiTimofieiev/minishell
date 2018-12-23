/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:20:20 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 18:03:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_index_envp(char **envp_find, char *name)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp_find[i])
	{
		if (ft_strncmp(envp_find[i], name, len) == 0)
		{
			if (envp_find[i][len] == '=')
				return (i);
		}
		i++;
	}
	return (0);
}

char **get_buf_envp(char **arguments, char **envp_init)
{
	int		i;
	int		len;
	char	**buf;
	char **tmp;
	i = 0;

	len = len_char_2d_array(envp_init);

	buf = copy_2d_char(envp_init);

    // ft_clean_2d_char(envp_init);

	tmp = (char **)malloc(sizeof(char *) * (len + 2));

	while (buf[i])
	{
		tmp[i] = ft_strdup(buf[i]);
		i++;
	}
	tmp[i] = ft_strnew(ft_strlen(arguments[1]) + 1 + ft_strlen(arguments[2]));
	ft_memset(tmp[i], 0x0, ft_strlen(arguments[1]) +
												1 + ft_strlen(arguments[2]));
	ft_strcat(tmp[i], arguments[1]);
	ft_strcat(tmp[i], "=");
	ft_strcat(tmp[i], arguments[2]);

	tmp[++i] = NULL;
	

 return (tmp);
}

char **envp_res_logic(char **arguments, char **envp_init, int i)
{
	if (ft_strequ(arguments[3], "1"))
	{
		free(envp_init[i]);
		envp_init[i] = ft_strnew(ft_strlen(arguments[1]) + 1 + ft_strlen(arguments[2]));
		ft_memset(envp_init[i], 0x0, ft_strlen(arguments[1]) + 1 + ft_strlen(arguments[2]));
		ft_strcat(envp_init[i], arguments[1]);
		ft_strcat(envp_init[i], "=");
		ft_strcat(envp_init[i], arguments[2]);
	}
	return (envp_init);
}

char **setenv_minishell(char *str, char **envp_init)
{
	int		i;
	char	**arguments;
	int		q_params;
	char 	**result = NULL;

	arguments = ft_strsplit(str, 32);
	q_params = len_char_2d_array(arguments);
	if (q_params < 3 || q_params > 4)
		ft_clean_2d_char(arguments);
	i = get_index_envp(envp_init, arguments[1]);
	if (i)
		result = envp_res_logic(arguments, envp_init, i);
	else
		result = get_buf_envp(arguments, envp_init);
	(arguments) ? ft_clean_2d_char(arguments) : 0;
	return (result);
}
