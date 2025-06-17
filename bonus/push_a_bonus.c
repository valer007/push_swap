/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:59:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/13 21:13:17 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_zero(char *str)
{
	int	count;
	int	num;

	num = 0;
	count = 0;
	while (str[count] == '0')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		num++;
		count++;
	}
	if (num > 10)
		return (0);
	return (1);
}

static int	check(long num)
{
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

static int	process_argument(t_list **st, char *arg)
{
	int		j;
	char	**str;
	t_list	*new;

	str = ft_split(arg, ' ');
	j = 0;
	if (!str)
		return (0);
	j = -1;
	while (str[++j])
	{
		if (!check_symbols(str[j]) || !check(ft_atol(str[j]))
			|| !check_zero(str[j]))
		{
			free_stack(st);
			return (free_string(str), 0);
		}
		new = ft_lstnew(ft_atol(str[j]));
		ft_lstadd_back(st, new);
	}
	j = 0;
	free_string(str);
	return (1);
}

int	push_a_bonus(t_list **st, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!process_argument(st, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
