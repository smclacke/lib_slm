/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ultimate_div_mod.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:28:30 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:31 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*b != 0)
	{
		div = (*a) / (*b);
		mod = (*a) % (*b);
		*a = div;
		*b = mod;
	}
}

int	main()
{
	int	a = 50;
	int	b = 2;

	printf("a: %d, b: %d\n", a, b);
	ultimate_div_mod(&a, &b);
	printf("a: %d, b: %d\n", a, b);
}
