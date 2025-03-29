/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:11:32 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/29 19:20:16 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "get_next_line.h"

int		main(int argc, char **argv);
void	pa(t_list **sta, t_list **stb);
void	pb(t_list **sta, t_list **stb);
void	rra(t_list **sta);
void	rrb(t_list **stb);
void	rrr(t_list **sta, t_list **stb);
void	ra(t_list **sta);
void	rb(t_list **stb);
void	rr(t_list **sta, t_list **stb);
void	sa(t_list **sta);
void	sb(t_list **stb);
void	ss(t_list **sta, t_list **stb);
int		push_a_bonus(t_list **st, int argc, char **argv);
void	checker_bonus(t_list **a, t_list **b);

#endif