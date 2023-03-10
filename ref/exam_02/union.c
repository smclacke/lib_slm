#include <unistd.h>

int	check_char(char *s, int index, char c)
{
	int	i = -1;
	while (++i < index)
		if (s[i] == c)
			return (0);
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int	i = -1;
	int	j = -1;
	while (s1[++i])
		if (check_char(s1, i, s1[i]))
			write(1, &s1[i], 1);
	while (s2[++j])
		if (check_char(s1, i, s2[j]) && check_char(s2, j, s2[j]))
			write(1, &s2[j], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

// ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e

// RETURN: df6vewg4thras

// zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e

// RETURN: zpadintoqefwjy

// "rien" "cette phrase ne cache rien" | cat -e

// RETURN: rienct phas
