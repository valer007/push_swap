/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:34:10 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/14 15:41:03 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	check_dublicate(t_list *a)
{
	t_list	*temp;
	t_list	*node;

	temp = a;
	while (temp)
	{
		node = a;
		while (node != temp)
		{
			if (temp->content == node->content)
				return (0);
			node = node->prev;
		}
		temp = temp->prev;
	}
	return (1);
}

static void	print_msg(t_list *sta, t_list *stb)
{
	if (!is_sorted(sta) && stb == NULL)
		ft_printf("KO\n");
	else if (is_sorted(sta) && stb == NULL)
		ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_list	*sta;
	t_list	*stb;

	if (argc < 2)
		return (0);
	if (!check_argv(argc, argv) || !check_space(argc, argv))
	{
		ft_printf("Error\n");
		exit(1);
	}
	sta = NULL;
	stb = NULL;
	if (!push_a_bonus(&sta, argc, argv) || !check_dublicate(sta))
	{
		ft_printf("Error\n");
		free_stack(&sta);
		exit(1);
	}
	checker_bonus(&sta, &stb);
	print_msg(sta, stb);
	free_stack(&sta);
	free_stack(&stb);
	return (0);
}
