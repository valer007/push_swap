/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:59:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/25 20:00:38 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	push_a(t_list **st, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			new = ft_lstnew(ft_atoi(str[j]));
			ft_lstadd_back(st, new);
			j++;
		}
		free(str);
		i++;
	}
}
