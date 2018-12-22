/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:34:12 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 12:37:52 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	path_handler(char **command_line, char *pwd_old, char **envp)
{
	char	*path_v;
	int		path[2];

	path[0] = detect_del_var("PWD", envp);
	path[1] = detect_del_var("OLDPWD", envp);
	path_v = get_global_var(envp, command_line[1]);
	if (chdir(path_v) == 0)
	{
		ft_clean(envp);
		envp[path[0]] = ft_strnew(4 + ft_strlen(path_v));
		ft_strcpy(envp[path[0]], "PWD=");
		ft_strcpy(&envp[path[0]][4], path_v);
		envp[path[1]] = ft_strdup(pwd_old);
	}
	if (path_v)
		free(path_v);
}

int		one_and_too_many_argv_hel_help(char **command_line,
										char **envp, char *pwd_old, int *path)
{
	char *path_v;

	if (command_line[1][0] == '-' && ft_strlen(command_line[1]) == 1)
	{
		path_v = get_global_var(envp, "$OLDPWD");
		chdir(path_v);
		ft_clean(envp);
		envp[path[0]] = ft_strnew(4 + ft_strlen(path_v));
		ft_strcpy(envp[path[0]], "PWD=");
		ft_strcpy(&envp[path[0]][4], path_v);
		envp[path[1]] = ft_strdup(pwd_old);
		(path_v != NULL) ? free(path_v) : 0;
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (1);
	}
	return (0);
}

int		one_and_too_many_argv_help(char **command_line,
									char **envp, char *pwd_old, int *path)
{
	if (command_line[1][0] == '$')
	{
		path_handler(command_line, pwd_old, envp);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (1);
	}
	else if ((command_line[1][0] == '-' && command_line[1][1] == '-'
				&& ft_strlen(command_line[1]) == 2))
	{
		chdir("/Users/otimofie");
		ft_clean(envp);
		envp[path[0]] = ft_strdup("PWD=/Users/otimofie");
		envp[path[1]] = ft_strdup(pwd_old);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (1);
	}
	else if (one_and_too_many_argv_hel_help(command_line, envp, pwd_old, path))
		return (1);
	return (0);
}

short	one_and_too_many_argv(char **command_line,
								char *pwd_old, char **envp)
{
	int path[2];

	path[0] = detect_del_var("PWD", envp);
	path[1] = detect_del_var("OLDPWD", envp);
	if (len_char_2d_array(command_line) == 1)
	{
		chdir("/Users/otimofie");
		ft_clean(envp);
		envp[path[0]] = ft_strdup("PWD=/Users/otimofie");
		envp[path[1]] = ft_strdup(pwd_old);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (0);
	}
	else if (len_char_2d_array(command_line) != 2)
	{
		ft_printf("%s%s%s\n", RED, "error: too many arguments", RESET);
		(command_line != NULL) ? ft_clean_2d_char(command_line) : 0;
		return (0);
	}
	else if (one_and_too_many_argv_help(command_line, envp, pwd_old, path))
		return (0);
	return (1);
}
