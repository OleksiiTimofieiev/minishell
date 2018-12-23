#include "../includes/minishell.h"

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

char	**cmd_array_constructor(char *line)
{
		char **cmd_array;

		change_to_spaces(line, '\t', ' ');

		if (ft_quantity_of_chars(line, ';'))
			cmd_array = ft_strsplit(line, ';');
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[0] = ft_strdup(line);
			cmd_array[1] = NULL;
		}
		return (cmd_array);
}
