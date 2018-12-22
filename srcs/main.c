/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:35:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 15:34:33 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// TODO: norminette (+rename funcs to static) & leaks

// TODO: check all in correction form;

char	**check(char **envp_buf)
{
	if (detect_del_var("OLDPWD", envp_buf) == 'x')
		envp_buf = setenv_minishell("setenv OLDPWD /Users/otimofie 1", envp_buf);
	 if (detect_del_var("PWD", envp_buf) == 'x')
		envp_buf = setenv_minishell("setenv PWD /Users/otimofie 1", envp_buf);
	// else if (detect_del_var("PATH", envp_buf) == 'x')
	// 	envp_buf = setenv_minishell("setenv PATH /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin", envp_buf);
	 if (detect_del_var("HOME", envp_buf) == 'x') // wtf ?
	{
		// ft_putstr("No home\n");
		envp_buf = setenv_minishell("setenv HOME /Users/otimofie 1", envp_buf);
	}
	return (envp_buf);
}

int		ft_quantity_of_chars(char *line, char c)
{
	int i;
	int quantity;

	i = 0;
	quantity = 0;
	while (line[i])
	{
		if (line[i] == c)
			quantity++;
		i++;
	}
	return (quantity);
}

void	change_to_spaces(char *str, char find, char required)
{
	while (*str)
	{
		if (*str == find)
			*str = required;
		str++;
	}
}

int 	detect_not_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32)
			return (i);
		i++;
	}
	return (i);
}

void 	minishell(char **envp_in)
{
	char	*line;
	char	**envp_buf;
	int		len_env_vars;
	char 	**cmd_array;
	int 	j;

	line = NULL;
	cmd_array = NULL;
	envp_buf = init_envp_buf(envp_in);
	len_env_vars = ft_2d_arr_size(envp_buf) - 1;

	while (1)
	{

		// len_env_vars = ft_2d_arr_size(envp_buf) - 1;
		envp_buf = check(envp_buf);
		ft_printf("%s%s%s", GREEN, "$> ", RESET);
		if (!(get_next_line(0, &line)))
			exit (0);

		change_to_spaces(line, '\t', ' ');

		if (ft_quantity_of_chars(line,';'))
		{
			ft_printf("We have some multiple instructions\r\n");
			cmd_array = ft_strsplit(line, ';');
//
//            int j = 0;
//            while (cmd_array[j])
//                ft_printf("%s\n", cmd_array[j++]);
		}
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[0] = ft_strdup(line);
			cmd_array[1] = NULL;
		}

		int i;

		i = 0;

		while (cmd_array[i])
		{
			ft_printf("%s%s%s\n", CYAN, "x\n", RESET);

			j = detect_not_space(cmd_array[i]);

			if (!ft_strncmp(&cmd_array[i][j], "cd", 2))
			{
//                ft_putstr("cd\n");

				cd(cmd_array[i], envp_buf);
			}
			else if (!ft_strncmp(&cmd_array[i][j], "echo", 4))
			{
//                ft_putstr("echo\n");
				echo(cmd_array[i], envp_buf);
			}
			else if (ft_strequ(&cmd_array[i][j], "env"))
				env_minishell(envp_buf);
			else if (!ft_strncmp(&cmd_array[i][j], "exit", 4))
				exit_minishell(envp_buf);
			else if (!ft_strncmp(&cmd_array[i][j], "setenv", 6))
				envp_buf = setenv_minishell(cmd_array[i], envp_buf);
			else if (!ft_strncmp(&cmd_array[i][j], "unsetenv", 8))
			{
				envp_buf = unsetenv_minishell(cmd_array[i], envp_buf);
				envp_buf = check(envp_buf);	

			}
			else
			{
				// ft_printf("%s%s%s", CYAN, "4\n", RESET);
				run_buitin_cmd(&cmd_array[i][j], envp_buf);
				// ft_printf("%s%s%s", CYAN, "5\n", RESET);
			}
			i++;
		}

		(line) ? free(line) : 0;
		
		(cmd_array != NULL) ? ft_clean_2d_char(cmd_array) : 0;
		system("leaks -q minishell");
	}
}

int		main(int argc, char **argv, char **envp)
{
	signal(SIGINT, signal_handler);

	(void)argc;
	(void)argv;

	minishell(envp);
    
	return (0);
}
