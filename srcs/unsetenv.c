/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:52:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 16:12:49 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		detect_del_var_un(char *env, char **haystack)
{
	int i;
	int len_of_env;

	i = 0;
	len_of_env = ft_strlen(env);
	while (haystack[i])
	{
		if (ft_strncmp(env, haystack[i], len_of_env) == 0)
		{
			if (haystack[i][len_of_env] == '=')
				return (i);
		}
		i++;
	}
	return (0);
}

char	**delete_var(char *env_var, char **envp_init)
{
	int		i;
	int		j;
	int		len;
	int		skip;
	char	**deleted;

	i = 0;
	j = 0;
	len = len_char_2d_array(envp_init);
	skip = detect_del_var_un(env_var, envp_init);
	deleted = (char **)malloc(sizeof(char *) * (len));
	while (j < len)
	{
		if (j == skip)
		{
			j++;
			continue ;
		}
		deleted[i++] = ft_strdup(envp_init[j++]);
	}
	deleted[i] = NULL;
	return (deleted);
}

char	**unsetenv_minishell(char *str, char **envp_init)
{
	char **envp_res;
	char **arguments;

	envp_res = NULL;
	arguments = ft_strsplit(str, 32);
	if (len_char_2d_array(arguments) != 2)
	{
		envp_res = copy_2d_char(envp_init);
		ft_clean_2d_char(arguments);
		ft_clean_2d_char(envp_init);
		ft_printf("%s%s%s", RED,
		"Wrong number of arguments -> has to be 1\n", RESET);
		return (envp_res);
	}
	if (!(envp_res = delete_var(arguments[1], envp_init)))
	{
		envp_res = copy_2d_char(envp_init);
		ft_clean_2d_char(arguments);
		ft_clean_2d_char(envp_init);
		ft_printf("%s%s%s", RED, "Permision denied.\n", RESET);
		return (envp_res);
	}
	(envp_init != NULL) ? ft_clean_2d_char(arguments) : 0;
	(envp_init != NULL) ? ft_clean_2d_char(envp_init) : 0;
	return (envp_res);
}
