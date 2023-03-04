/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fizz_buzz.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:44:06 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:47 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	numbers(int n)
{
	char	str[10] = "0123456789";

	if (n > 9)
		numbers(n / 10);
	write(1, &str[n % 10], 1);
}

int	main()
{
	int	n;
	
	n = 1;
	while (n <= 100)
	{
		if (n % 3 == 0 && n % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (n % 5 == 0)
			write(1, "fizz", 4);
		else if (n % 3 == 0)
			write(1, "buzz", 4);
		else 
			numbers(n);
		n++;
		write(1, "\n", 1);
	}
}
