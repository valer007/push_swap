/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:01:59 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/27 16:55:00 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_list **sta)
{
	t_list	*temp;
	t_list	*current;

	if (!*sta || !(*sta)->prev)
		return (0);
	temp = *sta;
	*sta = (*sta)->prev;
	current = *sta;
	while (current->prev)
		current = current->prev;
	current->prev = temp;
	temp->prev = NULL;
	return (1);
}

void	ra(t_list **sta)
{
	if (rotate(sta))
		ft_printf("ra\n");
}

void	rb(t_list **stb)
{
	if (rotate(stb))
		ft_printf("rb\n");
}

void	rr(t_list **sta, t_list **stb)
{
	if (rotate(sta) && rotate(stb))
		ft_printf("rr");
}
