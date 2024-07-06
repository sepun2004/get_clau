/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czamora- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:19:30 by czamora-          #+#    #+#             */
/*   Updated: 2024/07/06 20:14:24 by czamora-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

char	*read_and_store(int fd, char *stored, ssize_t bytes_read)
{
	char	*buf;
	char	*temp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (!stored)
			stored = ft_strdup("");
		temp = ft_strjoin(stored, buf);
		free(stored);
		stored = temp;
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read (fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes_read < 0)
		return (free(stored), NULL);
	if (bytes_read == 0 && (!stored || !*stored))
		return (free(stored), NULL);
	return (stored);
}

char	*extract_line(char **stored)
{
	char	*line;
	char	*temp;
	int		len;

	len = 0;
	while ((*stored)[len] && (*stored)[len] != '\n')
		len++;
	if ((*stored)[len] == '\n')
		len++;
	line = ft_substr(*stored, 0, len);
	if ((*stored)[len] != '\0')
		temp = ft_strdup(*stored + len);
	else
		temp = NULL;
	free(*stored);
	*stored = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stored = read_and_store(fd, stored, bytes_read);
	if (!stored || !*stored)
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	line = extract_line(&stored);
	return (line);
}
