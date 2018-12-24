#include "../includes/minishell.h"

void	change_to_necessary_char(char *str, char find, char required)
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

void	multy_replace(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		change_to_necessary_char(str[i], 34, ' ');
		change_to_necessary_char(str[i], 39, ' ');
		i++;
	}
}

char	**cmd_array_constructor(char *line)
{
		char **cmd_array;

		change_to_necessary_char(line, '\t', ' ');
		if (ft_quantity_of_chars(line, ';'))
			cmd_array = ft_strsplit(line, ';');
		else
		{
			cmd_array = (char **)malloc(sizeof(char *) * 2);
			cmd_array[0] = ft_strdup(line);
			cmd_array[1] = NULL;
		}
		if (quotes_validation(cmd_array))
		{
			multy_replace(cmd_array);
			return (cmd_array);
		}
		ft_printf("%s%s\n%s", RED, "Not valid quotes.", RESET);
		ft_clean_2d_char(cmd_array);
		return (NULL);
}
