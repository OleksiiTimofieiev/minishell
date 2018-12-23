/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:35:06 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/22 17:58:17 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	**check(char **envp_buf)
// {
// 	if (detect_del_var("OLDPWD", envp_buf) == 'x')
// 		envp_buf = setenv_minishell("setenv OLDPWD /Users/otimofie 1",
// 		envp_buf);
// 	if (detect_del_var("PWD", envp_buf) == 'x')
// 		envp_buf = setenv_minishell("setenv PWD /Users/otimofie 1", envp_buf);
// 	if (detect_del_var("HOME", envp_buf) == 'x')
// 		envp_buf = setenv_minishell("setenv HOME /Users/otimofie 1", envp_buf);
// 	return (envp_buf);
// }

// remaster main, cd, echo, exit, fork;

// test cd .. and cd
extern	char **environ;


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

int		detect_not_space(char *str)
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

void	execution_cycle(t_env **env, char **cmd_array)
{
	int i;
	int j;

	i = 0;
	while (cmd_array[i])
	{
		j = detect_not_space(cmd_array[i]);

		if (!ft_strncmp(&cmd_array[i][j], "cd", 2))
			cd(cmd_array[i], env);
// else if (!ft_strncmp(&cmd_array[i][j], "echo", 4))
// 	echo(str, envp_buf);
		else if (ft_strequ(&cmd_array[i][j], "env"))
			env_minishell(*env);
	// else if (!ft_strncmp(&cmd_array[i][j], "exit", 4))
	// 	exit_minishell(envp_buf);
	// else if (!ft_strncmp(&cmd_array[i][j], "setenv", 6))
	// {
	// 		test = setenv_minishell(str, envp_buf);
	// 		// test = buf;
	// }
	// // else if (!ft_strncmp(&cmd_array[i][j], "unsetenv", 8))
	// // {
	// // 	envp_buf = unsetenv_minishell(str, envp_buf);
	// // 	envp_buf = check(envp_buf);
	// // }
	else
		run_buitin_cmd(&cmd_array[i][j], env);

		i++;
	}
}

void    push_back(t_env **head, char *str)
{
    t_env   *new;
    t_env   *last;
    char    **split;
    
    split = ft_strsplit(str, '=');
    last = *head;

    new = (t_env *)malloc(sizeof(t_env));
    new->name = strdup(split[0]);
    new->content = strdup(split[1]);
    new->next = NULL;

    if (!*head)
        *head = new;
    else
    {
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

void	init_m(t_env **env)
{
	int i;

	i = 0;
	while (environ[i])
		push_back(env, environ[i++]);
}

void	minishell(t_env **env)
{
	char	*line;
	char	**cmd_array;

	ft_printf("%s%s\n%s", CYAN, "2", RESET);

	while (1)
	{
		ft_printf("%s%s%s", GREEN, "$> ", RESET);
		if (!(get_next_line(0, &line)))
			exit(0);

		change_to_spaces(line, '\t', ' ');

		if (ft_quantity_of_chars(line, ';'))
		{
			ft_printf("We have some multiple instructions\r\n");
			cmd_array = ft_strsplit(line, ';');
		}
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[0] = ft_strdup(line);
			cmd_array[1] = NULL;
		}
// 
		execution_cycle(env, cmd_array);

		(line) ? free(line) : 0;
		(cmd_array != NULL) ? ft_clean_2d_char(cmd_array) : 0;
	}
}

int		main(void)
{
	signal(SIGINT, signal_handler); // to minishell
	t_env	*env;
	ft_printf("%s%s\n%s", CYAN, "1", RESET);
	
	env = NULL;
	init_m(&env);

	minishell(&env);
		system("leaks -q minishell");

	return (0);
}
