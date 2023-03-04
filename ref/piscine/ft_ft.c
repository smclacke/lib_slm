/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ft.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:25:50 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:45:51 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *n)
{
	*n = 42;
}

int	main()
{
	int	*n;
	int nbr;

	nbr = 134;
	n = &nbr;

	ft_ft(n);
	printf("%d\n", nbr);
	return(0);
}
