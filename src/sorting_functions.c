/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:30:36 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/17 12:19:45 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->prev->content;
	third = (*stack)->prev->prev->content;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
	else if (first > second && first > third && second < third)
		ra(stack);
	else if (second > third && third > first && second > first)
	{
		rra(stack);
		sa(stack);
	}
}

void	sort_four(t_list **a, t_list **b)
{
	int	min_pos;

	min_pos = get_position((*a), find_min((*a)));
	while (min_pos--)
		ra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	min_pos;
	int	i;

	i = 2;
	while (i--)
	{
		min_pos = get_position((*a), find_min((*a)));
		if (min_pos <= ft_lstsize(*a) / 2)
			while (min_pos--)
				ra(a);
		else
			while (min_pos++ < ft_lstsize(*a))
				rra(a);
		pb(b, a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
