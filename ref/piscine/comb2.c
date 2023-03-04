/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comb2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:19:44 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:44:50 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	comb2(void)
{
	char	a;
	char	b;

	a = 0;
	b = 0;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			putchar(a / 10 + '0');
			putchar(a % 10 + '0');
			putchar(' ');
			putchar(b / 10 + '0');
			putchar(b % 10 + '0');
			b++;
			if(a != 98)
				write(1, ", ", 2);
		}
		a++;
	}
}

int	main()
{
	comb2();
}
