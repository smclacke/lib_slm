/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_int_tab.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:27:28 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:15 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				j = tab[i];
				tab[i] = tab [i + 1];
				tab [i + 1] = j;
			}
			i++;
		}
		size--;
	}
}

int	main()
{
	int	tab[3] = {7, 3, 8};
	int	size = 3;

	printf("%d, %d, %d\n", tab[0], tab[1], tab[2]);
	sort_int_tab(tab, size);
	printf("%d, %d, %d\n", tab[0], tab[1], tab[2]);
}
