/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:30:36 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/27 16:55:04 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **st)
{
	int	first;
	int	second;
	int	third;

	first = (*st)->content;
	second = (*st)->prev->content;
	third = (*st)->prev->prev->content;
	if (first > second && second < third && first < third)
		sa(st);
	else if (first > second && second > third)
	{
		sa(st);
		rra(st);
	}
	else if (first > second && first > third)
		ra(st);
	else if (first < second && second > third && first < third)
	{
		sa(st);
		ra(st);
	}
	else if (first < second && second > third)
		rra(st);
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
		while (min_pos--)
			ra(a);
		pb(b, a);
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
