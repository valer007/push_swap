/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:01:39 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/27 16:54:52 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (push(sta, stb))
		ft_printf("pa\n");
}

void	pb(t_list **sta, t_list **stb)
{
	if (push(sta, stb))
		ft_printf("pb\n");
}
