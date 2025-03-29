/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:04:33 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/29 22:40:43 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static int check_instr(t_list **a, t_list **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		return (sa(a), 1);
	else if (!ft_strcmp(str, "sb\n"))
		return (sb(b), 1);
	else if (!ft_strcmp(str, "ss\n"))
		return (ss(a, b), 1);
	else if (!ft_strcmp(str, "ra\n"))
		return (ra(a), 1);
	else if (!ft_strcmp(str, "rb\n"))
		return (rb(b), 1);
	else if (!ft_strcmp(str, "rr\n"))
		return (rr(a, b), 1);
	else if (!ft_strcmp(str, "rra\n"))
		return (rra(a), 1);
	else if (!ft_strcmp(str, "rrb\n"))
		return (rrb(b), 1);
	else if (!ft_strcmp(str, "rrr\n"))
		return (rrr(a, b), 1);
	else if (!ft_strcmp(str, "pa\n"))
		return (pa(a, b), 1);
	else if (!ft_strcmp(str, "pa\n"))
		return (pb(a, b), 1);
	return (0);
}

void checker_bonus(t_list **a, t_list **b)
{
	char *str;
	
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break;
		if(!check_instr(a, b, str))
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
}