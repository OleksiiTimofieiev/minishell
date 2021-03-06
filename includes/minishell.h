/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 13:42:26 by otimofie          #+#    #+#             */
/*   Updated: 2018/12/25 14:09:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>

typedef struct		s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}					t_env;

/*
**************************** core ******************************
*/

void				echo(char *str, t_env **env);
void				cd(char *str, t_env **env);
void				exit_minishell(t_env **env);
void				env_minishell(t_env *env);
void				signal_handler(int sig_num);
void				run_buitin_cmd(char *line, t_env *env);
void				setenv_minishell(char *str, t_env *env);
void				unsetenv_minishell(char *str, t_env *env);

/*
**************************** infrastructure ********************
*/

void				push_back(t_env **head, char *str);
void				init_env(char **envp, t_env **env);
void				ft_clean(t_env **env);
int					detect_del_var(char *env, char **haystack);
short				one_and_too_many_argv(char **command_line,
					char *pwd_old, t_env **env);
t_env				*find_elem(t_env **env, char *str);
int					env_var_detection(char *str);
int					spaces_quantity(char **arguments, int start_index);
char				*find_binary_path(char *binary_name, t_env **env_array);
void				special_char(char **arguments, t_env *env);
void				special_char_fork(char **arguments, t_env *env);
void				tilda_fork(char **arguments);
void				check_special_env(t_env *env);
void				change_to_spaces(char *str, char find, char required);
int					detect_not_space(char *str);
char				**cmd_array_constructor(char *line);
int					quotes_validation(char **str);
int					find_char(char *str, char c);
void				woohoo_help(char **path, char *env_value, char *str, int j);
int					special_char_occurance_fork(char *str);
void				special_char_help_fork(char **argument, t_env *env);
int					find_char_fork(char *str, char c);
int					find_char_setenv(char *str, char c);

#endif
