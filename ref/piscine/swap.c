/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:28:02 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:24 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main()
{
	int	n = 9;
	int	g = 6;

	printf("n: %d, g: %d\n", n, g);
	swap(&n, &g);
	printf("n: %d, g: %d\n", n, g);
}
