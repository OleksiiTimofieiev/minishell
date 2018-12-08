/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:40:09 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/08 21:01:03 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_global_variable(char *str, char **envp)
{
	int i;
	int j;

	i = 0;
	while (envp[i])
	{
		if (!ft_strequ(envp[i], "$") && ft_strncmp(envp[i], &str[1], ft_strlen(&str[1])) == 0 
			&& (envp[i][ft_strlen(&str[1])] == '='))
		{
			j = 0;
			while (envp[i][j] != '=')
				j++;
			ft_printf("%s", &envp[i][j + 1]);
		}
		i++;
	}
}

int		spaces_quantity(char **arguments, int start_index)
{
	int		result;

	result = 0;
	while (arguments[start_index])
	{
		result++;
		start_index++;
	}
	return (result);
}

void	display_arguments(char **arguments, char **envp, int n_flag)
{
	int		start_index;
	int		spaces;
	int		spaces_iterator;

	start_index = (n_flag) ? 2 : 1;
	spaces = spaces_quantity(arguments, start_index);
	spaces_iterator = 0;
	while (arguments[start_index])
	{
		if (arguments[start_index][0] == '$'
			&& ft_strlen(arguments[start_index]) != 1)
			display_global_variable(arguments[start_index++], envp);
		else
		{
			if (arguments[start_index][0] == '~')
			{
				ft_printf("/Users/otimofie");
				ft_putstr(&arguments[start_index++][1]);
			}
			else
				ft_putstr(arguments[start_index++]);
		}
		if (spaces_iterator++ + 1 < spaces)
			ft_printf(" ");
	}
}

void	echo(char *str, char **envp)
{
	char	**command_line;
	int		n_flag;

	n_flag = 0;
	command_line = ft_strsplit(str, 32);

	// int i = 0;
	// while (command_line[i])
	// 	ft_printf("%s\n", command_line[i++]);

	if (ft_strequ("-n", command_line[1]))
		n_flag = 1;
	display_arguments(command_line, envp, n_flag);
	if (!n_flag)
		ft_printf("\n");
	ft_clean_2d_char(command_line);
}
