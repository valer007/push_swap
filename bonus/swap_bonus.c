/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:17:54 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/31 01:01:29 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	swap(t_list **st)
{
	t_list	*tmp;

	if (!(*st) || !(*st)->prev)
		return (0);
	tmp = *st;
	*st = (*st)->prev;
	tmp->prev = (*st)->prev;
	(*st)->prev = tmp;
	return (1);
}

void	sa(t_list **sta)
{
	swap(sta);
}

void	sb(t_list **stb)
{
	swap(stb);
}

void	ss(t_list **sta, t_list **stb)
{
	swap(sta);
	swap(stb);
}
