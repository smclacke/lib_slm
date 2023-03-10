/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: SarahLouise <SarahLouise@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:52:40 by SarahLouise       #+#    #+#             */
/*   Updated: 2023/03/10 11:23:21 by SarahLouise      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strjoin(char *line, char c)
{
	char *tmp;
	int i = 0, j = 0;
	if (!line)
	{
		tmp = (char*)malloc(2);
		tmp[0] = c;
		tmp[1] = 0;
	}
	else
	{
		while(line[i])
			i++;
		tmp = (char*)malloc(i + 2);
		while(j < i)
		{
			tmp[j] = line[j];
			j++;
		}
		tmp[j] = c;
		tmp[j+1] = 0;
		free(line);
	}
	return (tmp);
}

int get_next_line(char **line)
{
	char *tmp = NULL;
	char c = 0;
	if (tmp == NULL)
		tmp = ft_strjoin(tmp, '\0');
	while (read(0, &c, 1) && c != '\n')
	{
		tmp = ft_strjoin(tmp, c);
	}
	*line = tmp;
	return (c=='\n');
}

int
	main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
}

// size_t		ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i] != '\0')
// 		++i;
// 	return (i);
// }

// char		*ft_strnew(int size)
// {
// 	char	*str;

// 	str = (char *)malloc(sizeof(char) * (size + 1));
// 	if (!str)
// 		return (NULL);
// 	str[size] = '\0';
// 	return (str);
// }

// char		*ft_strjoin(char *s1, char *s2)
// {
// 	char	*joint;
// 	int		i;
// 	int		j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	joint = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!joint)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i] != '\0')
// 	{
// 		joint[i] = s1[i];
// 		++i;
// 	}
// 	free(s1);
// 	while (s2[j] != '\0')
// 	{
// 		joint[i] = s2[j];
// 		++i;
// 		++j;
// 	}
// 	joint[i] = '\0';
// 	return (joint);
// }

// int			get_next_line(char **line)
// {
// 	char	*buf;
// 	int		n;

// 	buf = (char *)malloc(sizeof(char) * 2);
// 	n = 0;
// 	if (!line || (read(0, buf, 0)) < 0)
// 		return (-1);
// 	*line = ft_strnew(0);
// 	while ((n = read(0, buf, 1)))
// 	{
// 		if (buf[0] == '\n')
// 		{
// 			free(buf);
// 			return (1);
// 		}
// 		buf[n] = '\0';
// 		*line = ft_strjoin(*line, buf);
// 	}
// 	free(buf);
// 	return (0);
// }