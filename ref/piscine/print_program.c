/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_program.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:32:33 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:45:59 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int c;

	c = 0;
	if (argc > 0)
	{
		while (argv[0][c])
		{
			write(1, &argv[0][c], 1);
			c++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
