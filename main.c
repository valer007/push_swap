/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:00:38 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/30 17:50:22 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] == NULL || argv[i][0] == '\0')
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

	if (argc < 2 || !check_argv(argc, argv))
	{
		ft_printf("Error");
		exit(0);
	}
	sta = NULL;
	stb = NULL;
	if (!push_a(&sta, argc, argv) || !check_dublicate(sta))
	{
		ft_printf("Error");
		exit(0);
	}
	size = get_size(sta);
	push_swap(&sta, &stb, size);
	free_stack(&sta);
	free_stack(&stb);
}
