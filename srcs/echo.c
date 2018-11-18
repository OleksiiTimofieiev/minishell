/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:40:09 by otimofie          #+#    #+#             */
/*   Updated: 2018/11/18 13:40:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		check_till_equal(char *haystack, char *needle)
{
	while (*needle && *haystack)
	{
		if (*needle != *haystack)
			return (0);
		needle++;
		haystack++;
	}
	if (*(haystack + 1) == '=')
		return (1);
	return (0);
}

void	display_global_variable(char *str, char **envp)
{
	while (*envp)
	{
		if (!ft_strequ(*envp, "$") && check_till_equal(*envp, str))
			ft_printf("%s", *envp);
		envp++;
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
			display_global_variable(arguments[start_index], envp);
		else
			ft_printf("%s", arguments[start_index]);
		if (spaces_iterator + 1 < spaces)
		{
			ft_printf(" ");
		}
		start_index++;
		spaces_iterator++;
	}
}

void	echo(char *str, char **envp)
{
	char	**command_line;
	int		n_flag;

	n_flag = 0;
	command_line = ft_strsplit(str, 32);
	if (ft_strequ("-n", command_line[1]))
		n_flag = 1;
	display_arguments(command_line, envp, n_flag);
	if (!n_flag)
		ft_printf("\n");
	ft_clean_2d_char(command_line);
}
