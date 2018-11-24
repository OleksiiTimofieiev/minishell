/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/24 16:07:08 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd(char *str, char **envp)
{
	char **command_line;
	char pwd_old[1024];
	char *pwd_new;

	command_line = ft_strsplit(str, 32); // not one argument;

	ft_memset(pwd_old, 0x0, sizeof(pwd_old));
	ft_strcat(pwd_old, "OLDPWD=");

	getcwd(&pwd_old[7], sizeof(pwd_old));
	
	pwd_new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 5));
	ft_memset(pwd_new, 0x0, sizeof(pwd_new));
	ft_strcat(pwd_new, "PWD=");
	ft_strcat(pwd_new, command_line[1]);


	if (chdir(command_line[1]) == 0)
	{
		envp[6] = pwd_new;
		envp[22] = pwd_old;
	}
	
	else
	{
		some error management...
	}
	
	ft_printf("old->%s%s%s\n", CYAN, envp[22], RESET);
	ft_printf("new->%s%s%s\n", CYAN, envp[6], RESET);

	free(pwd_new);

	ft_clean_2d_char(command_line);
}
