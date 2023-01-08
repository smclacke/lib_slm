/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 14:44:15 by smclacke      #+#    #+#                 */
/*   Updated: 2023/01/08 15:20:25 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s, int temp)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)temp)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s1, '\0');
	s2 = (char *)malloc(i + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, i + 1);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen((char *)s1, '\0');
	j = ft_strlen((char *)s2, '\0');
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
	{
		free((char *)s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, i + 1);
	ft_strlcpy(str + i, s2, j + 1);
	free((char *)s1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(src, '\0');
	if (dstsize == 0)
		return (len);
	while (i < dstsize - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
