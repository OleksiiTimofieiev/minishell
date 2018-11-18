/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:38:21 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/12 16:38:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_n_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		ft_n_let(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		q_w;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	q_w = ft_n_words((char *)s, c);
	res = (char **)malloc(sizeof(*res) * (ft_n_words((char *)s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (q_w--)
	{
		while (*s == c && *s != '\0')
			s++;
		res[i] = ft_strsub((char *)s, 0, ft_n_let((char *)s, c));
		if (res[i] == NULL)
			return (NULL);
		s = s + ft_n_let(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
