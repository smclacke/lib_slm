/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_params.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:32:55 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:09 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	j = argc - 1;
	while (argc > 1)
	{
		while (j > 0)
		{
			i = 0;
			while (argv[j][i])
			{
				write(1, &argv[j][i], 1);
				i++;
			}
			write(1, " ", 1);
			j--;
		}
	}
	return (0);
}

