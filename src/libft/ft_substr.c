/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:57:47 by smclacke      #+#    #+#                 */
/*   Updated: 2022/11/04 00:27:43 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > (ft_strlen(s) - start))
	{
		len = (ft_strlen(s) - start);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
