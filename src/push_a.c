/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:59:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/30 15:55:46 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	process_argument(t_list **st, char *arg)
{
	int		j;
	char	**str;
	t_list	*new;

	str = ft_split(arg, ' ');
	j = 0;
	// while(str[j]) {
	// 	ft_printf("%s\n", str[j]);
	// 	j++;
	// }
	if (!str)
		return (0);
	j = 0;
	while (str[j])
	{
		if (!check_symbols(str[j]) || !check(ft_atol(str[j]))
			|| !check_zero(str[j]))
			return (0);
		new = ft_lstnew(ft_atol(str[j]));
		ft_lstadd_back(st, new);
		j++;
	}
	j = 0;
	while (str[j])
		free(str[j++]);
	free(str);
	return (1);
}

int	push_a(t_list **st, int argc, char **argv)
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
