/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 04:20:13 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:32:16 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Reads a line from a file descriptor (FD) into a buffer. 
 * The `get_next_line_map` function handles the core logic, 
 * maintaining static storage for unprocessed data between calls. 
 * It uses helper functions like `set_char` to check 
 * for newline characters, `put_stash` to read more data 
 * from the file if needed, 
 * `get_line` to extract the current line from the accumulated buffer, 
 * and `rest_stash` to store any remaining characters for the next read. 
 * Returns a line from the file each time it is called, 
 * or NULL when no more data is available or an error occurs. 
 */

int	set_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*put_stash(int fd, char *stash)
{
	int		val;
	char	*buf;

	val = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (!set_char(stash) && val != 0)
	{
		val = read(fd, buf, BUFFER_SIZE);
		if (val < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[val] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*get_line(char *stat)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	len = 0;
	if (stat[i] == 0)
		return (NULL);
	while (stat[len] != '\n' && stat[len])
		len++;
	if (stat[len] == '\n')
		len++;
	line = (char *)malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[len] = '\0';
	while (i < len)
	{
		line[i] = stat[i];
		i++;
	}
	return (line);
}

char	*rest_stash(char *stash)
{
	int		i;
	int		start;
	char	*rest;

	i = 0;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	start = i;
	i = 0;
	rest = (char *)malloc((ft_strlen(stash) - start + 1) * sizeof(char));
	if (!rest)
		return (NULL);
	start--;
	while (stash[++start])
		rest[i++] = stash[start];
	rest[i] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line_map(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = put_stash(fd, stash);
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	line = get_line(stash);
	stash = rest_stash(stash);
	if (!stash)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
