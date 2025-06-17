/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:04:33 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/14 15:51:19 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_list *a)
{
	if (!a)
		return (1);
	while (a->prev)
	{
		if (a->content > a->prev->content)
			return (0);
		a = a->prev;
	}
	return (1);
}

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

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

static int	check_instr(t_list **a, t_list **b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (sa(a), 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (sb(b), 1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (ss(a, b), 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (pa(a, b), 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (pb(b, a), 1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ra(a), 1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (rb(b), 1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (rr(a, b), 1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (rra(a), 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (rrb(b), 1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (rrr(a, b), 1);
	return (0);
}

void	checker_bonus(t_list **a, t_list **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!check_instr(a, b, str))
		{
			ft_printf("Error\n");
			free(str);
			get_next_line(-1);
			free_stack(a);
			free_stack(b);
			exit(1);
		}
		free(str);
	}
}
