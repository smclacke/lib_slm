/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parasum.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:48:16 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:48:22 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Assignment name  : paramsum
// Expected files   : paramsum.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays the number of arguments passed to it, followed by
// a newline.

// If there are no arguments, just display a 0 followed by a newline.

// Example:

// $>./paramsum 1 2 3 5 7 24
// 6
// $>./paramsum 6 12 24 | cat -e
// 3$
// $>./paramsum | cat -e
// 0$
// $>

void	ft_putnbr(int n)
{
	char	number;
	
	if (n >= 10)
		ft_putnbr(n / 10);
	number = (n % 10) + '0';
	write(1, &number, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
