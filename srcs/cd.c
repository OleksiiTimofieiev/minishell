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

char	*get_cool_path(void)
{
	char cool_path[1024];

	ft_memset(cool_path, 0x0, sizeof(cool_path));
	// ft_strcat(cool_path, pwd_new);
	getcwd(cool_path, sizeof(cool_path));
	return (ft_strdup(cool_path));
}

short	cd_main(char *pwd_new, char *pwd_old, t_env **env, char **command_line)
{
	t_env *path_x;
	t_env *path_y;

	path_x = find_elem(env, "PWD");
	path_y = find_elem(env, "OLDPWD");
	if (chdir(pwd_new) == 0)
	{
		ft_clean(env);
		path_x->content = get_cool_path();
		path_y->content = ft_strdup(pwd_old);
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
	if (command_line[1][0] == '~' && command_line[1][1] == '/')
	{
		ft_strcat(pwd_new, "/Users/otimofie");
		ft_strcat(pwd_new, &command_line[1][1]);
	}
	else
		ft_strcat(pwd_new, command_line[1]);
}

void	cd(char *str, t_env **env)
{
	int		len;
	char	*pwd_new;
	char	**command_line;
	char	pwd_old[1024];

	len = 0;
	command_line = ft_strsplit(str, 32);
	ft_memset(pwd_old, 0x0, sizeof(pwd_old));
	getcwd(pwd_old, sizeof(pwd_old));
	if (!one_and_too_many_argv(command_line, pwd_old, env))
		return ;
	len = (command_line[1][0] == '~') ? len += ft_strlen("/Users/otimofie") : 0;
	pwd_new = ft_strnew((ft_strlen(command_line[1]) + 1 + len));
	ft_memset(pwd_new, 0x0, sizeof(pwd_new));
	tilda(command_line, pwd_new);
	if (!cd_main(pwd_new, pwd_old, env, command_line))
	{
		(pwd_new) ? free(pwd_new) : 0;
		ft_clean_2d_char(command_line);
		return ;
	}
	free(pwd_new);
	ft_clean_2d_char(command_line);
}
