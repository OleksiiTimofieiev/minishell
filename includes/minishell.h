#ifndef MINISHELL_H
#define MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>

void	echo(char *str, char **envp);
void	cd(char *str, char **envp);
void	exit_minishell(char **envp);

char	*get_global_var(char **envp, char *command);
void	ft_clean(char **envp);

#endif