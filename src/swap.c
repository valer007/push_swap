/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:53:46 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/29 16:48:13 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (swap(sta))
		ft_printf("%s\n", "sa");
}

void	sb(t_list **stb)
{
	if (swap(stb))
		ft_printf("%s\n", "sb");
}

void	ss(t_list **sta, t_list **stb)
{
	if (swap(sta) && swap(stb))
		ft_printf("%s\n", "ss");
}
