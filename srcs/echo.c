/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:40:09 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 13:52:22 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	display_global_variable(char *str, t_env *env, int index)
{
	while (env)
	{
		if (!ft_strequ(env->name, "$") && ft_strncmp(env->name,
			&str[index], ft_strlen(&str[index])) == 0)
		{
			ft_printf("%s", env->content);
			break ;
		}
		env = env->next;
	}
}

void	display_arguments_help_2(char **arguments, int *start_index)
{
	if (arguments[(*start_index)][0] == '~')
	{
		ft_printf("/Users/otimofie");
		ft_putstr(&arguments[(*start_index)++][1]);
	}
	else
		ft_putstr(arguments[(*start_index)++]);
}

void	display_arguments_help_1(char **arguments,
	int *start_index, t_env **env)
{
	int		i;
	char	**env_arguments;

	env_arguments = ft_strsplit(arguments[*start_index], '$');
	i = 0;
	while (env_arguments[i])
		display_global_variable(env_arguments[i++], *env, 0);
	ft_clean_2d_char(env_arguments);
	(*start_index)++;
}

void	display_arguments(char **arguments, t_env **env, int n_flag)
{
	int		start_index;
	int		spaces;
	int		spaces_iterator;

	start_index = (n_flag) ? 2 : 1;
	spaces = spaces_quantity(arguments, start_index);
	spaces_iterator = 0;
	while (arguments[start_index])
	{
		if (env_var_detection(arguments[start_index]))
			display_arguments_help_1(arguments, &start_index, env);
		else if (arguments[start_index][0] == '$'
				&& ft_strlen(arguments[start_index]) != 1)
			display_global_variable(arguments[start_index++], *env, 1);
		else
			display_arguments_help_2(arguments, &start_index);
		if (spaces_iterator++ + 1 < spaces)
			ft_printf(" ");
	}
}

void	echo(char *str, t_env **env)
{
	char	**command_line;
	int		n_flag;

	n_flag = 0;
	command_line = ft_strsplit(str, 32);
	if (ft_strequ("-n", command_line[1]))
		n_flag = 1;
	display_arguments(command_line, env, n_flag);
	if (!n_flag)
		ft_printf("\n");
	ft_clean_2d_char(command_line);
}
