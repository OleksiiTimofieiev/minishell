#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>

void	echo(char *str, char **envp);
void	cd(char *str, char **envp);
void	exit_minishell(char **envp);
void 	env_minishell(char **envp);
int		setenv_minishell(char *str, char **envp);











char	*get_global_var(char **envp, char *command);
char	**init_envp_buf(char **envp);
void	ft_clean(char **envp);

#endif