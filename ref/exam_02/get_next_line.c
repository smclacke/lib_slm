/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 13:57:26 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/10 15:02:17 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <fcntl.h>

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strnew(int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i = 0;
	int		j = 0;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j])
		str[++i] = s2[++j];
	str[i] = '\0';
	return (str);
}

int	get_next_line(char **line)
{
	char 	*buffer;
	int		n;
	buffer = (char *)malloc(sizeof(char) * 2);
	n = 0;
	if (!line || (read(0, buffer, 0)) < 0)
		return (-1);
	*line = ft_strnew(0);
	while ((n = read(0, buffer, 1)))
	{
		if (buffer[0] == '\n')
		{
			free(buffer);
			return (1);
		}
		buffer[n] = '\0';
		*line = ft_strjoin(*line, buffer);
	}
	free(buffer);
	return (0);
}

int	main(void)
{
	int		n;
	char	*line;

	while ((n = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	line = NULL;
}
