/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:20:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_cool_path(char *pwd_new)
{
	char cool_path[1024];

	ft_memset(cool_path, 0x0, sizeof(cool_path));
	ft_strcat(cool_path, pwd_new);
	getcwd(&cool_path[4], sizeof(cool_path));
	return (ft_strdup(cool_path));
}

short	cd_main(char *pwd_new, char *pwd_old, char **envp, char **command_line)
{
	int path[2];

	path[0] = detect_del_var("PWD", envp);
	path[1] = detect_del_var("OLDPWD", envp);
	if (chdir(&pwd_new[4]) == 0)
	{
		ft_clean(envp);
		envp[path[0]] = get_cool_path(pwd_new);
		envp[path[1]] = ft_strdup(pwd_old);
		return (1);
	}
	else
	{
		if (access(&pwd_new[4], F_OK) == -1)
			ft_printf("%s%s%s%s\n", RED, "cd: no such file or directory: ",
				command_line[1], RESET);
		else if (access(&pwd_new[4], R_OK) == -1)
			ft_printf("%s%s%s%s\n", RED, "cd: permission denied: ",
					command_line[1], RESET);
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
	ft_strcpy(pwd_new, "PWD=");
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
