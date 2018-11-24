/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:28:48 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/24 15:29:58 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd(char *str, char **envp)
{
	char **command_line;

	command_line = ft_strsplit(str, 32);
	
	ft_printf("%s\n", envp[6]);

	if (chdir(str) == 0)
	{
		envp[6] = "PWD=/Users/otimofie/Desktop/minishell/srcs/";
		ft_printf("%s\n", "SUCCESS");
	}
	ft_printf("%s\n", envp[6]);



	ft_clean_2d_char(command_line);
}

