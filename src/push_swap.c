/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:32:39 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/27 20:16:28 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	optimaizer(int size)
{
	int	sqrt;
	int	log;

	sqrt = 1;
	log = 0;
	while (sqrt < size / sqrt)
		sqrt++;
	while (size)
	{
		size /= 2;
		log++;
	}
	return (sqrt + log - 1);
}

static void	push_to_b(t_list **a, t_list **b, int *counter, int n)
{
	while (*a)
	{
		if ((*a)->index <= *counter)
		{
			pb(b, a);
			rb(b);
			(*counter)++;
		}
		else if ((*a)->index <= *counter + n)
		{
			pb(b, a);
			(*counter)++;
		}
		else
			ra(a);
	}
}

static void	push_back_to_a(t_list **a, t_list **b)
{
	int	max_pos;

	while (*b)
	{
		max_pos = get_position(*b, find_max(*b));
		if (max_pos <= get_size(*b) / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			while (max_pos++ < get_size(*b))
				rrb(b);
		}
		pa(a, b);
	}
}

void	push_swap(t_list **a, t_list **b, int size)
{
	int	counter;
	int	n;

	if (is_sorted(*a))
		return ;
	else if (size == 2)
		return (sa(a));
	else if (size == 3)
		return (sort_three(a));
	else if (size == 4)
		return (sort_four(a, b));
	else if (size == 5)
		return (sort_five(a, b));
	counter = 0;
	n = optimaizer(size);
	push_to_b(a, b, &counter, n);
	push_back_to_a(a, b);
}
