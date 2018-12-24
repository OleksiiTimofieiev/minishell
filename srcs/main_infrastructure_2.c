#include "../includes/minishell.h"


int		quotes_check(char *str)
{
	int	quotes_type_1;
	int	quotes_type_2;

	quotes_type_1 = 0;
	quotes_type_2 = 0;
	while (*str)
	{
		if (*str == 34)
			quotes_type_1++;
		else if (*str == 39)
			quotes_type_2++;
		str++;
	}
	if (quotes_type_1 % 2 == 0 && quotes_type_2 % 2 == 0)
		return (1);
	return (0);
}

int		quotes_validation(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!quotes_check(str[i]))
			return (0);
		i++;
	}
	return (1);

}