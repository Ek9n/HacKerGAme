/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:29:16 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:29:19 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*justline(char **buf, size_t *i, size_t *len)
{
	char	*line;

	*len = ft_gnllen(*buf);
	while ((*buf)[++(*i)])
	{
		if ((*buf)[*i] == '\n')
			break ;
	}
	line = (char *)ft_calloc_gnl((*i) + 2);
	if (line == NULL)
		return (line);
	ft_gnllcpy(line, *buf, (*i) + 2);
	if (*len == (*i))
	{
		free(*buf);
		*buf = NULL;
		return (line);
	}
	return (line);
}

static char	*nline_andbuf(char **buf)
{
	char		*line;
	char		*newbuf;
	size_t		len;
	size_t		i;
	size_t		j;

	i = -1;
	j = 0;
	line = justline(buf, &i, &len);
	if (*buf == NULL)
		return (line);
	if (line == NULL)
		return (line);
	len = len - i;
	newbuf = *buf;
	*buf = (char *)ft_calloc_gnl(len);
	if (*buf == NULL)
		return (*buf);
	while (i < ft_gnllen(newbuf))
		(*buf)[j++] = newbuf[1 + i++];
	free(newbuf);
	return (line);
}

static char	*gnl_join(char *a, char *b)
{
	char	*joined;
	size_t	len;
	size_t	jsize;
	size_t	i;

	i = 0;
	len = ft_gnllen(a) + ft_gnllen(b);
	joined = (char *)ft_calloc_gnl(len + 1);
	if (joined == NULL)
		return (joined);
	ft_gnllcpy(joined, a, ft_gnllen(a) + 1);
	jsize = ft_gnllen(joined);
	while (jsize + i < len && b[i] != '\0')
	{
		joined[jsize + i] = b[i];
		i++;
	}
	joined[jsize + i] = '\0';
	free(a);
	free(b);
	return (joined);
}

static char	*get_line_with_n(int fd, char **buf)
{
	int			go;
	char		*tmp;
	char		*joined;
	ssize_t		r;

	go = 1;
	while (go)
	{
		tmp = (char *)ft_calloc_gnl(BUFFER_SIZE + 1);
		if (tmp == NULL)
			return (tmp);
		r = read(fd, tmp, BUFFER_SIZE);
		if (ft_strchr(tmp, '\n'))
			go = 0;
		joined = gnl_join(*buf, tmp);
		if (joined == NULL)
			return (joined);
		*buf = joined;
		if ((r > 0 && r < BUFFER_SIZE) || (r == 0 && ft_gnllen(*buf) > 0))
			return (*buf);
		if (r <= 0)
			return (0);
	}
	return (*buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (!buf)
		buf = (char *)ft_calloc_gnl(1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_freebuf(&buf));
	if (ft_strchr(buf, '\n'))
		line = nline_andbuf(&buf);
	else
	{
		line = get_line_with_n(fd, &buf);
		if (line == NULL)
			return (ft_freebuf(&buf));
		line = nline_andbuf(&buf);
	}
	if (line == NULL)
		return (0);
	return (line);
}
