/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:52:16 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 16:35:32 by otimofie         ###   ########.fr       */
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
		if (ft_strncmp(env, haystack[i], len_of_env) == 0) //
			return (i);
		i++;
	}
	return (0);
}

char	**delete_var(char *env_var, char **envp_init /*, int len_env_vars*/)
{
	int		i;
	int		j;
	int		len;
	int		skip;
	char	**deleted;

	i = 0;
	j = 0;

	len = len_char_2d_array(envp_init);

	skip = detect_del_var(env_var, envp_init);

	deleted = (char **)malloc(sizeof(char *) * (len));
	// ft_printf("%s%s%s", CYAN, "1\n", RESET);
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
	// ft_printf("%s%s%s", CYAN, "2\n", RESET);
	return (deleted);
}

char	**unsetenv_minishell(char *str, char **envp_init /*, int len_env_vars*/)
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
		ft_printf("%s%s%s", RED, "Wrong number of arguments -> has to be 1\n", RESET);
		return (envp_res);
	}
	if (NULL == (envp_res = delete_var(arguments[1], envp_init/*, len_env_vars*/)))
	{
		envp_res = copy_2d_char(envp_init);
		ft_clean_2d_char(arguments);
		ft_clean_2d_char(envp_init);
		ft_printf("%s%s%s", RED, "Permision denied.\n", RESET);
		return (envp_res);
	}
	ft_clean_2d_char(arguments);
	ft_clean_2d_char(envp_init);
	return (envp_res);
}
