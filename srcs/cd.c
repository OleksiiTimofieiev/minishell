/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/24 21:52:22 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// 	2. parameter can not be accessed;

void		ft_clean(char **envp)
{
	if (envp[6])
		free(envp[6]);
	if (envp[22])
		free(envp[22]);
}

static int	len_2d_array(char **array)
{
	short i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

short	cd_main(char *pwd_new, char *pwd_old, char **envp, char **command_line)
{
	if (chdir(&pwd_new[4]) == 0)
	{
		ft_clean(envp);
		envp[6] = ft_strdup(pwd_new);
		envp[22] = ft_strdup(pwd_old);
		return (1);
	}
	else
	{
		ft_printf("%s%s%s%s\n", RED, "cd: no such file or directory: ",
					command_line[1], RESET);
		ft_clean(envp);
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

char	*get_global_var(char **envp, char *command_line) // test with setenv;
{
	int	i;
	char *buf;
	char *result;

	i = 0;
	buf = NULL;
	result = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], &(command_line[1]), ft_strlen(&(command_line[1]))) == 0)
		{
			buf = ft_strdup(envp[i]);
			break;
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

short	one_and_too_many_argv(char **command_line, char *pwd_old, char **envp)
{
	char *path;

	if (len_2d_array(command_line) == 1)
	{
		chdir("/Users/otimofie");
		ft_clean(envp);
		envp[6] = ft_strdup("/Users/otimofie");
		envp[22] = ft_strdup(pwd_old);
		ft_clean_2d_char(command_line);
		return (0);
	}
	else if (len_2d_array(command_line) != 2)
	{
		ft_printf("%s%s%s\n", RED, "error: too many arguments", RESET);
		ft_clean_2d_char(command_line);
		return (0);
	}
	else if (command_line[1][0] == '$')
	{
		path = get_global_var(envp, command_line[1]);
		ft_printf("path->%s\n", path);
		if (chdir(path) == 0)
		{
			ft_clean(envp);
			envp[6] = ft_strdup(path);
			envp[22] = ft_strdup(pwd_old);
		}
		if (path)
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
