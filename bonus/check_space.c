#include "push_swap_bonus.h"

int	check_space(int argc, char **argv)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == ' ')
		{
			j++;
		}
		if (j == ft_strlens(argv[i]))
			return (0);
		i++;
	}
	return (1);
}