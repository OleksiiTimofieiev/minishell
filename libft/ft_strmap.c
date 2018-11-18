/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:40:22 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/11 21:40:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*res;

	if (s != NULL & f != NULL)
	{
		size = ft_strlen(s) + 1;
		if (!(res = (char*)malloc(sizeof(*res) * (size))))
			return (0);
		i = 0;
		while (s[i])
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
