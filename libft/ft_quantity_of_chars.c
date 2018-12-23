#include "libft.h"

int		ft_quantity_of_chars(char *line, char c)
{
	int i;
	int quantity;

	i = 0;
	quantity = 0;
	while (line[i])
	{
		if (line[i] == c)
			quantity++;
		i++;
	}
	return (quantity);
}
