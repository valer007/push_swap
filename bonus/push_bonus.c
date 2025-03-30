/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 21:17:48 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/31 00:59:14 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	push(t_list **sta, t_list **stb)
{
	t_list	*temp;

	if (!(*stb))
		return (0);
	temp = (*stb);
	(*stb) = (*stb)->prev;
	temp->prev = *sta;
	*sta = temp;
	return (1);
}

void	pa(t_list **sta, t_list **stb)
{
	push(sta, stb);
}

void	pb(t_list **sta, t_list **stb)
{
	push(sta, stb);
}
