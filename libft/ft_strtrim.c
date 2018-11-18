/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:15:16 by otimofie          #+#    #+#             */
/*   Updated: 2017/11/12 13:15:17 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t')
		l--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		l--;
		i++;
	}
	str = ft_strnew(l);
	if (str == NULL)
		return (ft_strdup(""));
	s += i;
	str = ft_strncpy(str, s, l);
	return (str);
}
