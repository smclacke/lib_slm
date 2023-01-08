/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 14:43:48 by smclacke      #+#    #+#                 */
/*   Updated: 2023/01/08 15:21:59 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next(char **mem, int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(*mem);
		return (NULL);
	}
	if (read_bytes == 0)
		return (*mem);
	buffer[read_bytes] = '\0';
	if (!*mem)
		*mem = ft_strdup(buffer);
	else
		*mem = ft_strjoin(*mem, buffer);
	if (ft_strchr(*mem, '\n'))
		return (*mem);
	return (get_next(mem, fd));
}

char	*store_next(char **mem, size_t length)
{
	size_t	i;
	char	*line;

	i = ft_strlen(*mem, '\0') - length;
	if (i == 0 || !ft_strchr(*mem, '\n'))
	{
		free(*mem);
		return (NULL);
	}
	line = ft_strdup(*mem + length);
	free(*mem);
	return (line);
}

char	*give_next(char **mem)
{
	char	*line;
	int		i;

	if (ft_strchr(*mem, '\n'))
		i = ft_strlen(*mem, '\n') + 1;
	else
		i = ft_strlen(*mem, '\0');
	line = malloc((i + 1) * sizeof(char));
	if (!line)
	{
		free(*mem);
		return (NULL);
	}
	ft_strlcpy(line, *mem, i + 1);
	*mem = store_next(mem, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*mem[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read (fd, 0, 0) < 0)
	{
		free(mem[fd]);
		mem[fd] = NULL;
		return (NULL);
	}
	mem[fd] = get_next(&mem[fd], fd);
	if (!mem[fd])
		return (NULL);
	line = give_next(&mem[fd]);
	return (line);
}
