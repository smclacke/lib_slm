/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_params.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:33:19 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:20 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, const char **argv)
{
	int	count;
	int	i;
	int	j;
	int	arg[argc];

	count = 1;
	i = 1;
	while (count < argc)
	{
		arg[count] = count;
		count++;
	}
	while (i < argc)
	{
		j = i;
		while (j < argc)
		{
			if (strcmp(argv[arg[i]], argv[arg[j]]) > 0)
				swap(&arg[i], &arg[j]);
			j++;
		}
		putstr(argv[arg[i++]]);
	}
	return(0);
}

