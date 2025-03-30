/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:34:10 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/30 21:47:44 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int	check_dublicate(t_list *a)
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
	if (is_sorted(sta) || stb != NULL)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

static void	free_stack(t_list **stack)
{
	t_list	*temp;

	temp = NULL;
	while ((*stack))
	{
		temp = *stack;
		*stack = (*stack)->prev;
		free(temp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*sta;
	t_list	*stb;

	if (argc < 2 || !check_argv(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	sta = NULL;
	stb = NULL;
	if (!push_a_bonus(&sta, argc, argv) || !check_dublicate(sta))
	{
		ft_printf("Error\n");
		exit(1);
	}
	checker_bonus(&sta, &stb);
	print_msg(sta, stb);
	free_stack(&sta);
	free_stack(&stb);
	return (0);
}
