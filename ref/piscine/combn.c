/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combn.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:17:05 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:45:12 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int *t, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < n)
	{
		if (t[i - 1] >= t[i])
			j = 0;
		i++;
	}
	if (j)
	{
		i = 0;
		while (i < n)
			putchar(t[i++] + 48);
		if (t[0] < (10 - n))
		{
			write(1, ", ", 2);
		}
	}
}

void combn(int n)
{
	int	i;
	int	t[n];

	i = 0;
	while (i < n)
		t[i++] = 0;
	while (t[0] <= (10 - n) && n >= 1 && n < 10)
	{
		print(t, n);
		t[n - 1]++;
		i = n - 1;
		while (i && n > 1)
		{
			if (t[i] > 9)
			{
				t[i - 1]++;
				t[i] = 0;
			}
			i--;
		}
	}
}


int	main()
{
	combn(5);
}
