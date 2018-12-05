#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>
# include <dirent.h>
# include <stdio.h> // delete;

void	echo(char *str, char **envp);
void	cd(char *str, char **envp);
void	exit_minishell(char **envp);
void 	env_minishell(char **envp);
char	**setenv_minishell(char *str, char **envp);
char	**unsetenv_minishell(char *str, char **envp_init);




int lsh_launch(char **env_array);






char	*get_global_var(char **envp, char *command);
char	**init_envp_buf(char **envp);
void	ft_clean(char **envp);

#endif