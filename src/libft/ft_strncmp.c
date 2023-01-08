/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 20:41:55 by smclacke      #+#    #+#                 */
/*   Updated: 2022/11/04 00:26:41 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)(s1)[i] != (unsigned char)(s2)[i])
		{
			return ((unsigned char)(s1)[i] - (unsigned char)(s2)[i]);
		}
		i++;
	}
	return (0);
}
