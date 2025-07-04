/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:00:38 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/17 13:59:43 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i] == NULL || argv[i][0] == '\0')
			return (0);
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' && argv[i][j - 1] >= '0'
					&& argv[i][j - 1] <= '9')
				|| (argv[i][j] == '+' && argv[i][j - 1] >= '0'
					&& argv[i][j - 1] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_space(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_list	*sta;
	t_list	*stb;
	int		size;

	if (argc < 2)
		return (0);
	if (!check_argv(argc, argv) || !check_space(argc, argv))
	{
		ft_printf("Error");
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	sta = NULL;
	stb = NULL;
	if (!push_a(&sta, argc, argv) || !check_dublicate(sta))
	{
		ft_printf("Error");
		free_stack(&sta);
		exit(0);
	}
	size = get_size(sta);
	push_swap(&sta, &stb, size);
	free_stack(&sta);
	free_stack(&stb);
}
