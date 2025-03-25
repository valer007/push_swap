/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:56:05 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/25 19:57:01 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

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
	if (reverse_rotate(sta))
		ft_printf("rra\n");
}

void	rrb(t_list **stb)
{
	if (reverse_rotate(stb))
		ft_printf("rrb\n");
}

void	rrr(t_list **sta, t_list **stb)
{
	if (reverse_rotate(sta) && reverse_rotate(stb))
		ft_printf("rrr\n");
}
