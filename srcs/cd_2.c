/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:34:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:32:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	path_handler(char **command_line, char *pwd_old, t_env **env)
{
	char	*path_v;
	t_env	*find_env;
	t_env 	*path_x;
	t_env 	*path_y;


	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");
	find_env = find_elem(env, &command_line[1][1]);
	path_v = ft_strdup(find_env->content);

	if (chdir(path_v) == 0)
	{
		ft_clean(env);
		path_x->content = ft_strdup(path_v);
		path_y->content = ft_strdup(pwd_old);
	}
	if (path_v != NULL)
		free(path_v);
}

int		one_and_too_many_argv_hel_help(char **command_line,
										t_env **env, char *pwd_old)
{
	t_env *path_x;
	t_env *path_y;

	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");
	char *path_v;

	if (command_line[1][0] == '-' && ft_strlen(command_line[1]) == 1)
	{
		path_v = ft_strdup(path_y->content);
		chdir(path_v);
		ft_clean(env);
		path_x->content = ft_strdup(path_v);
		path_y->content = ft_strdup(pwd_old);
		(path_v != NULL) ? free(path_v) : 0;
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (1);
	}
	return (0);
}

int		one_and_too_many_argv_help(char **command_line,
									t_env **env, char *pwd_old)
{
	t_env *path_x;
	t_env *path_y;


	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");
	if (command_line[1][0] == '$')
	{
		path_handler(command_line, pwd_old, env);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (1);
	}
	else if ((command_line[1][0] == '-' && command_line[1][1] == '-'
				&& ft_strlen(command_line[1]) == 2))
	{
		chdir("/Users/otimofie");
		ft_clean(env);
		path_x->content = ft_strdup("/Users/otimofie");
		path_y->content = ft_strdup(pwd_old);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (1);
	}
	else if (one_and_too_many_argv_hel_help(command_line, env, pwd_old))
		return (1);
	return (0);
}

short	one_and_too_many_argv(char **command_line,
								char *pwd_old, t_env **env)
{
	t_env *path_x;
	t_env *path_y;

	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");
	if (len_char_2d_array(command_line) == 1)
	{
		chdir("/Users/otimofie");
		ft_clean(env);
		path_x->content = ft_strdup("/Users/otimofie");
		path_y->content = ft_strdup(pwd_old);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;

		return (0);
	}
	else if (len_char_2d_array(command_line) != 2)
	{
		ft_printf("%s%s%s\n", RED, "error: too many arguments", RESET);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (0);
	}
	else if (one_and_too_many_argv_help(command_line, env, pwd_old))
		return (0);
	return (1);
}
