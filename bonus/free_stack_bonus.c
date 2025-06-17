/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:12:16 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/12 16:12:17 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;

	temp = NULL;
	while ((*stack))
	{
		temp = *stack;
		*stack = (*stack)->prev;
		free(temp);
	}
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
