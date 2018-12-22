#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>

void	echo(char *str, char **envp);
void	cd(char *str, char **envp);
void	exit_minishell(char **envp);
void 	env_minishell(char **envp);
char	**setenv_minishell(char *str, char **envp);
char	**unsetenv_minishell(char *str, char **envp_init);
void	run_buitin_cmd(char *line, char **env_array);
char	*get_global_var(char **envp, char *command);
char	**init_envp_buf(char **envp);
void	ft_clean(char **envp);
void	signal_handler(int sig_num);
int		detect_del_var(char *env, char **haystack);
short	one_and_too_many_argv(char **command_line, char *pwd_old, char **envp);

#endif