/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/24 16:34:02 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// manage cd $ENVVAR
// manage ~/.../

short	len_2d_array(char **array)
{
	short i;

	i = 0;
	while (array[i])
		i++;
	return i;
}

void	cd(char *str, char **envp)
{
	char **command_line;
	char pwd_old[1024];
	char *pwd_new;

	command_line = ft_strsplit(str, 32);
	if (len_2d_array(command_line) != 2)
	{
		ft_printf("%s%s%s\n", RED, "error: too many arguments", RESET);
		exit(0);
	}

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
		ft_printf("%s\n", "dir has been changed");
	}
	else
	{
		ft_printf("%s%s%s%s\n", RED, "cd: no such file or directory: ", command_line[1], RESET);
		exit(0);
	}

	
	// else
	// {
	// 	some error management...
	// 	add some validation:command_line
	// 	1. more then one parameter
	// 	2. parameter can not be accessed;
	// }
	
	ft_printf("old->%s%s%s\n", CYAN, envp[22], RESET);
	ft_printf("new->%s%s%s\n", CYAN, envp[6], RESET);

	free(pwd_new);

	ft_clean_2d_char(command_line);
}
