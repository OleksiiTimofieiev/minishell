/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:24:35 by otimofie          #+#    #+#             */
/*   Updated: 2018/03/09 12:10:06 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lt		*l_new(int fd)
{
	t_lt	*tmp;

	if (!(tmp = malloc(sizeof(*tmp))))
		return (NULL);
	if (!(tmp->content = ft_strnew(0)))
	{
		free(tmp);
		return (NULL);
	}
	tmp->fd = fd;
	tmp->next = NULL;
	return (tmp);
}

t_lt		*l_find(t_lt *list, int fd)
{
	t_lt	*new;

	while (list->next)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	if (list->fd == fd)
		return (list);
	if (!(new = l_new(fd)))
		return (NULL);
	list->next = new;
	return (new);
}

t_lt		*get_data_to_the_list(t_lt *list, int fd)
{
	int		ret;
	char	*str;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = list->content;
		if (!(list->content = ft_strjoin(list->content, buf)))
			return (NULL);
		ft_strdel(&str);
		if (ft_strchr(list->content, '\n'))
			break ;
	}
	if (ret < 0)
		return (NULL);
	return (list);
}

int			get_data_to_line(t_lt *list, char **line)
{
	char	*index;
	char	*str;

	if (list->content && *(list->content))
	{
		if (!(index = ft_strchr(list->content, '\n')))
		{
			*line = list->content;
			list->content = NULL;
		}
		else
		{
			*line = ft_strnew(index - list->content);
			ft_memcpy(*line, list->content, index - list->content);
			str = list->content;
			list->content = ft_strdup(++index);
			ft_strdel(&str);
		}
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_lt	*list;
	t_lt		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, 0, 0))
		return (-1);
	if (!list)
		list = l_new(fd);
	tmp = list;
	tmp = l_find(tmp, fd);
	if (!(tmp = get_data_to_the_list(tmp, fd)))
		return (-1);
	ret = get_data_to_line(tmp, line);
	return ((ret > 0 ? 1 : 0));
}
