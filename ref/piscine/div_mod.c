/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   div_mod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:25:21 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:44:35 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

int	main()
{
	int	a = 50;
	int	b = 2;
	int	*div = &a;
	int	*mod = &b;

	printf("a: %d, b: %d\n", a, b);
	div_mod(a, b, div, mod);
	printf("a: %d, b: %d\n", a, b);
}
