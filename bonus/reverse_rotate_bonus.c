/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:14:06 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/28 20:17:08 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	reverse_rotate(t_list **sta)
{
	t_list	*temp;
	t_list	*current;

	if (!*sta || !(*sta)->prev)
		return (0);
	temp = *sta;
	while (temp->prev->prev)
		temp = temp->prev;
	current = temp->prev;
	current->prev = *sta;
	temp->prev = NULL;
	*sta = current;
	return (1);
}

void	rra(t_list **sta)
{
	reverse_rotate(sta);
}

void	rrb(t_list **stb)
{
	reverse_rotate(stb);
}

void	rrr(t_list **sta, t_list **stb)
{
	reverse_rotate(sta);
	reverse_rotate(stb);
}