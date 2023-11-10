/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:33:01 by seojchoi          #+#    #+#             */
/*   Updated: 2023/04/24 15:16:56 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*find_buf(t_list **backup, int fd)
{
	t_list	*cur;
	t_list	*new;

	cur = *backup;
	while (cur)
	{
		if (cur -> fd == fd)
			return (cur);
		if (cur -> next == 0)
			break ;
		cur = cur -> next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (new == 0)
		return (0);
	new -> fd = fd;
	new -> buf = NULL;
	new -> next = NULL;
	if (*backup == 0)
		*backup = new;
	else
		cur->next = new;
	return (new);
}

char	*read_file(t_list *backup, char *buff, int fd, int read_size)
{
	char	*tmp;

	while (!ft_strchr(backup -> buf, '\n'))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1 || read_size == 0)
			break ;
		buff[read_size] = '\0';
		if (!backup -> buf)
			backup -> buf = ft_strdup(buff);
		else
		{
			tmp = backup -> buf;
			backup -> buf = ft_strjoin(tmp, buff);
			free(tmp);
		}
	}
	free(buff);
	buff = 0;
	if (backup -> buf == 0)
		return (0);
	if ((read_size == 0 && backup->buf == 0) || read_size == -1)
		return (0);
	return (backup -> buf);
}

char	*make_line(char *buf)
{
	int		idx;
	char	*res;

	idx = 0;
	while (buf[idx] != '\0' && buf[idx] != '\n')
		idx++;
	if (buf[idx] == '\0')
		res = (char *)malloc(sizeof(char) * idx + 1);
	else
		res = (char *)malloc(sizeof(char) * idx + 2);
	if (res == 0)
		return (0);
	idx = 0;
	while (buf[idx] && buf[idx] != '\n')
	{
		res[idx] = buf[idx];
		idx++;
	}
	if (buf[idx] == '\n')
		res[idx++] = '\n';
	res[idx] = '\0';
	return (res);
}

char	*make_backup(char *buf)
{
	int		idx;
	char	*new_backup;

	idx = 0;
	while (buf[idx] != '\0' && buf[idx] != '\n')
		idx++;
	if (buf[idx] == '\0' || buf[idx + 1] == '\0')
	{
		free(buf);
		buf = 0;
		return (0);
	}
	new_backup = ft_strdup(&buf[idx + 1]);
	free(buf);
	buf = 0;
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static t_list	*backup;
	t_list			*cur_buf;
	char			*line;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	cur_buf = find_buf(&backup, fd);
	if (cur_buf == 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (check_free(backup, &backup, fd));
	if (!read_file(cur_buf, buff, fd, 1))
		return (check_free(backup, &backup, fd));
	else
	{
		line = make_line(cur_buf -> buf);
		if (line == 0)
			return (check_free(backup, &backup, fd));
	}
	cur_buf -> buf = make_backup(cur_buf -> buf);
	if (!(cur_buf -> buf))
		check_free(backup, &backup, fd);
	return (line);
}
