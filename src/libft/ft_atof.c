/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 16:21:46 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/03 16:33:32 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	check_hex(char *str, int *neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	n;
	int		neg;
	double	div;

	n = 0;
	div = 0.1;
	neg = 1;
	i = check_hex(str, &neg);
	while (str[i] && ft_isdigit(str[i] && str[i] != '.'))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		n = n + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (0);
	return (n * neg);
}

// int	main()
// {
// 	printf("%f\n", ft_atof("34656"));
// }
