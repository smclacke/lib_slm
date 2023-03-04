/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_int_tab.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/04 15:26:58 by smclacke      #+#    #+#                 */
/*   Updated: 2023/03/04 15:46:05 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (size / 2))
	{
		j = tab[i];
		tab[i] = tab [size - 1 - i];
		tab [size - 1 - i] = j;
		i++;
	}
}

int	main()
{
	int	tab[5] = {0, 1 , 2, 3, 4};
	int	size = 5;
	printf("%d, %d, %d, %d, %d\n", tab [0], tab [1], tab[2], tab[3], tab[4]);
	rev_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d\n", tab [0], tab [1], tab[2], tab[3], tab[4]);
}
