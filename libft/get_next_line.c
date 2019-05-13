/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltkache <oltkache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:23:20 by oltkache          #+#    #+#             */
/*   Updated: 2017/12/22 16:34:49 by oltkache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_realoc(char *save, int i, char *line)
{
	char	*new;
	int		j;
	int		k;

	new = NULL;
	if (!save)
	{
		if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
	}
	else if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(save) + i + 1))))
		return (NULL);
	j = 0;
	if (save)
		while (save[j] != '\0')
		{
			new[j] = save[j];
			++j;
		}
	k = 0;
	while (k < i)
		new[j++] = line[k++];
	new[j] = '\0';
	ft_strdel(&save);
	return (new);
}

char	*ft_re_save(char *save, int i)
{
	char *new;

	if (save[i] == '\0')
	{
		ft_strdel(&save);
		return (ft_strdup("\0"));
	}
	new = ft_strdup(&save[i + 1]);
	ft_strdel(&save);
	return (new);
}

void	ft_new_fd(t_list **l, int fd, t_list **new)
{
	t_list *head;

	if (*l)
	{
		if (fd != (int)((*l)->content_size))
		{
			head = *l;
			while (head != NULL)
			{
				if ((int)(head->content_size) == fd && (*new = head))
					return ;
				head = head->next;
			}
			*new = ft_lstnew(NULL, 0);
			(*new)->content_size = fd;
			ft_lstadd(l, *new);
		}
		else
			*new = *l;
		return ;
	}
	*l = ft_lstnew(NULL, 0);
	(*l)->content_size = fd;
	*new = *l;
}

int		ft_gnl(t_list **s, int fd)
{
	char	*buf;
	int		i;

	buf = NULL;
	if ((*s)->content == NULL || !ft_strchr((char*)((*s)->content), '\n'))
	{
		if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		while ((i = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[i] = '\0';
			(*s)->content = (void*)ft_realoc((char*)((*s)->content), i, buf);
			if (ft_strchr(buf, '\n') != NULL)
				break ;
		}
		ft_strdel(&buf);
		if (((*s)->content && ((char*)((*s)->content))[0] == '\0' && i == 0) ||
			(!((*s)->content) && i == 0))
			return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	t_list			*s;
	static t_list	*list = NULL;
	char			*buf;
	int				i;

	if (fd < 0 || line == NULL || read(fd, NULL, 0) < 0)
		return (-1);
	ft_new_fd(&list, fd, &s);
	i = ft_gnl(&s, fd);
	if (i <= 0)
		return (i);
	i = 0;
	while (((char*)(s->content))[i] != '\n' && ((char*)(s->content))[i] != 0)
		++i;
	buf = ft_strnew(i + 1);
	i = -1;
	while (((char*)(s->content))[++i] != '\n' && ((char*)(s->content))[i] != 0)
		buf[i] = ((char*)(s->content))[i];
	buf[i] = '\0';
	*line = buf;
	s->content = ft_re_save((char*)(s->content), i);
	return (1);
}
