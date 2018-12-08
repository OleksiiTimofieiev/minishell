/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 17:34:07 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// var index, not fixed one;
// if pwd, oldpwd is NULL;

#include "../includes/minishell.h"

char *get_cool_path(char *pwd_new)
{
	char cool_path[1024];

	ft_memset(cool_path, 0x0, sizeof(cool_path));
	ft_strcat(cool_path, pwd_new);
	getcwd(&cool_path[4], sizeof(cool_path));
	return (ft_strdup(cool_path));
}

short	cd_main(char *pwd_new, char *pwd_old, char **envp, char **command_line)
{
	if (chdir(&pwd_new[4]) == 0)
	{
		ft_clean(envp);
		envp[6] = get_cool_path(pwd_new);
		envp[22] = ft_strdup(pwd_old);
		return (1);
	}
	else
	{
		if (access(&pwd_new[4], F_OK) == -1)
		{
			ft_printf("%s%s%s%s\n", RED, "cd: no such file or directory: ",
					command_line[1], RESET);
		}
		else if (access(&pwd_new[4], R_OK) == -1)
		{
			ft_printf("%s%s%s%s\n", RED, "cd: permission denied: ",
					command_line[1], RESET);
		}
		else
			ft_printf("%s%s%s%s\n", RED, "not a directory: ",
					command_line[1], RESET);
		return (0);
	}
}

void	tilda(char **command_line, char *pwd_new)
{
	if (command_line[1][0] == '~')
	{
		ft_strcat(pwd_new, "/Users/otimofie");
		ft_strcat(pwd_new, &command_line[1][1]);
	}
	else
		ft_strcat(pwd_new, command_line[1]);
}

void	path_handler(char **command_line, char *pwd_old, char **envp)
{
	char *path;

	path = get_global_var(envp, command_line[1]);
	if (chdir(path) == 0)
	{
		ft_clean(envp);
		envp[6] = ft_strdup(path);
		envp[22] = ft_strdup(pwd_old);
	}
	if (path)
		free(path);
	ft_clean_2d_char(command_line);
}

short	one_and_too_many_argv(char **command_line, char *pwd_old, char **envp)
{
	if (len_char_2d_array(command_line) == 1)
	{
		chdir("/Users/otimofie");
		ft_clean(envp);
		envp[6] = ft_strdup("PWD=/Users/otimofie");
		envp[22] = ft_strdup(pwd_old);
		ft_clean_2d_char(command_line);
		return (0);
	}
	else if (len_char_2d_array(command_line) != 2)
	{
		ft_printf("%s%s%s\n", RED, "error: too many arguments", RESET);
		ft_clean_2d_char(command_line);
		return (0);
	}
	else if (command_line[1][0] == '$')
	{
		path_handler(command_line, pwd_old, envp);
		return (0);
	}
	else if ((command_line[1][0] == '-' && command_line[1][1] == '-' 
		&& ft_strlen(command_line[1]) == 2))
	{
		chdir("/Users/otimofie");
		ft_clean(envp);
		envp[6] = ft_strdup("PWD=/Users/otimofie");
		envp[22] = ft_strdup(pwd_old);
		ft_clean_2d_char(command_line);
		return (0);
	}
	else if ((command_line[1][0] == '-' && ft_strlen(command_line[1]) == 1))
	{
		ft_putstr("work2\n");
		
		char *path;

		path = get_global_var(envp, "$OLDPWD");

		ft_putstr(path);

		chdir(path);
		ft_clean(envp);
		envp[6] = ft_strdup("PWD=");
		ft_strcat(envp[6], path);
		envp[22] = ft_strdup(pwd_old);

		free(path);
		ft_clean_2d_char(command_line);

		return (0);
	}
	return (1);
}

void	cd(char *str, char **envp)
{
	char	**command_line;
	char	pwd_old[1024];
	char	*pwd_new;
	int		len;

	len = 0;
	command_line = ft_strsplit(str, 32);
	ft_memset(pwd_old, 0x0, sizeof(pwd_old));
	ft_strcat(pwd_old, "OLDPWD=");
	getcwd(&pwd_old[7], sizeof(pwd_old));
	if (!one_and_too_many_argv(command_line, pwd_old, envp))
		return ;
	len = (command_line[1][0] == '~') ? len += ft_strlen("/Users/otimofie") : 0;
	pwd_new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 4 + 1 + len));
	ft_memset(pwd_new, 0x0, sizeof(pwd_new));
	ft_strcat(pwd_new, "PWD=");
	tilda(command_line, pwd_new);
	if (!cd_main(pwd_new, pwd_old, envp, command_line))
	{
		(pwd_new) ? free(pwd_new) : 0;
		ft_clean_2d_char(command_line);
		return ;
	}
	free(pwd_new);
	ft_clean_2d_char(command_line);
}
