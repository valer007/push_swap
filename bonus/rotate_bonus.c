/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:15:53 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/30 21:26:01 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	rotate(sta);
}

void	rb(t_list **stb)
{
	rotate(stb);
}

void	rr(t_list **sta, t_list **stb)
{
	rotate(sta);
	rotate(stb);
}
