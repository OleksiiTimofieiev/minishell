#include "../includes/minishell.h"

int		special_char_occurance(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '$')
			i++;
		str++;
	}
	return (i);
}

int		find_char_setenv(char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = i;
			return (j);
		}
		i++;
	}
	return (j);
}

void	woohoo_help_setenv(char **path, char *env_value, char *str, int j)
{
	*path = ft_strnew(ft_strlen(env_value) + 1 + ft_strlen(&str[j + 1]));
	ft_strcat(*path, env_value);
	ft_strcat(*path, "/");
	ft_strcat(*path, &str[j + 1]);
}

char 	*woohoo_setenv(char *str, t_env **env)
{
	int		j;
	char	*path;
	char	*env_value;
	char	*buf;
	t_env	*test;

	path = NULL;
	env_value = NULL;
	buf = NULL;
	j = find_char_setenv(str, '/');
	if (j)
	{
		str[j] = '\0';
		buf = ft_strdup(&str[1]);
		test = find_elem(env, buf);
		if (test)
			env_value = ft_strdup(find_elem(env, buf)->content);
		if (env_value)
		{
			woohoo_help_setenv(&path, env_value, str, j);
		}
	}
	(env_value) ? free(env_value) : 0;
	(buf) ? free(buf) : 0;
	return (path);
}

void	special_char_help(char **arguments, t_env *env)
{
	char	*slash;
	char 	*buf;
	char    *copy;

	slash = NULL;
	buf = NULL;
	copy = ft_strdup(arguments[2]);
	buf = woohoo_setenv(copy, &env);
	if (buf)
		slash = ft_strdup(buf);
	if (slash)
	{
		free(arguments[2]);
		arguments[2] = ft_strdup(slash);
	}	
	(copy) ? free(copy) : 0;
	(buf) ? free(buf) : 0;
	(slash) ? free(slash) : 0;
}

void	special_char(char **arguments, t_env *env)
{
	t_env	*env_local;

	if (arguments[2][0] == '$' && special_char_occurance(arguments[2]) == 1)
	{
		if (!find_char_setenv(arguments[2], '/'))
		{
			env_local = find_elem(&env, &arguments[2][1]);
			if (env_local)
			{
				free(arguments[2]);
				arguments[2] = ft_strdup(env_local->content);
			}
		}
		else
		{
			special_char_help(arguments, env);
		}
	}
}