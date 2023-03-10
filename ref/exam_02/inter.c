#include <unistd.h>

void	ft_inter(char *s1, char *s2)
{
	int	i = -1;
	int	j;

	char tmp[255];

	while (s1[++i])
	{
		j = -1;
		while (s2[++j])
		{
			if (tmp[(int)s1[i]] != 1 && (s1[i] == s2[j]))
			{
				write(1, &s1[i], 1);
				tmp[(int)s1[i]] = 1;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

// "nothing" "this sentence hides nothing" | cat -e

// nothig 

// ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e

// df6ewg4

// "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e

// padinto
