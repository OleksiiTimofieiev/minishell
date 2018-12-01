/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:52:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/01 15:31:54 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		detect_del_var(char *env, char **haystack)
{
	int i;
	int len_of_env;

	i = 0;
	len_of_env = ft_strlen(env);
	while (haystack[i])
	{
		ft_printf("%s\n", haystack[i]);
		if (!ft_strncmp(env, haystack[i], len_of_env))
			return (i);
		i++;
	}
	return (i);
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
	len = len_char_2d_array(envp_init) - 1;
	skip = detect_del_var(env_var, envp_init);

	deleted = NULL;
	deleted = (char **)malloc(sizeof(char *) * len + 1);
	deleted[len] = NULL;

	ft_printf("%sskip->%d%s\n", CYAN, skip, RESET);

	while (i < len)
	{
		if (j != skip)
		{
			deleted[i] = ft_strdup(envp_init[j]);
			i++;
		}
		j++;
	}
	return (deleted);
}

char	**unsetenv_minishell(char *str, char **envp_init)
{
	char **envp_res;
	char **arguments;

	envp_res = NULL;
	arguments = ft_strsplit(str, 32);
	envp_res = delete_var(arguments[1], envp_init);
	ft_clean_2d_char(arguments);
	ft_clean_2d_char(envp_init);
	return (envp_res);
}
