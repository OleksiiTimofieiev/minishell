#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>



typedef struct      s_env
{
    char            *name;
    char            *content;
    struct  s_env   *next;
}                   t_env;

// void	echo(char *str, char **envp);
void	cd(char *str, t_env **env);
// void	exit_minishell(char **envp);
void 	env_minishell(t_env *env);
void	signal_handler(int sig_num);

// char 	**setenv_minishell(char *str, char **envp);

// char	**unsetenv_minishell(char *str, char **envp_init);
void	run_buitin_cmd(char *line, t_env **env);
// char	*get_global_var(char **envp, char *command);
// char	**init_envp_buf(char **envp);
void	ft_clean(t_env **env);
int		detect_del_var(char *env, char **haystack);
short	one_and_too_many_argv(char **command_line, char *pwd_old, t_env **env);
t_env   *find_elem(t_env **env, char *str);
// int		env_var_detection(char *str);
// int		spaces_quantity(char **arguments, int start_index);
char	*find_binary_path(char *binary_name, t_env **env_array);

#endif