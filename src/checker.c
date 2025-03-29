/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:04:33 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/28 18:27:04 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_symbols(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| ((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] != '-' && str[i + 1] != '+')))
		{
			if ((str[i] == '-' && str[i + 1] == '-')
				|| (str[i] == '+' && str[i + 1] == '+'))
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	check_dublicate(t_list *a)
{
	t_list	*temp;
	t_list	*node;

	temp = a;
	while (temp)
	{
		node = a;
		while (node != temp)
		{
			if (temp->content == node->content)
				return (0);
			node = node->prev;
		}
		temp = temp->prev;
	}
	return (1);
}
