/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <vmakarya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:11:32 by vmakarya          #+#    #+#             */
/*   Updated: 2025/06/13 21:23:54 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "get_next_line.h"

void	free_string(char **str);
void	print_stack(t_list *st);
int		push_a(t_list **sta, int argc, char **argv);
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
int		find_min(t_list *st);
int		find_max(t_list *st);
int		get_position(t_list *st, int content);
int		get_size(t_list *st);
int		is_sorted(t_list *st);
void	sort_three(t_list **sta);
void	sort_five(t_list **sta, t_list **stb);
void	sort_four(t_list **sta, t_list **stb);
void	push_swap(t_list **sta, t_list **stb, int size);
int		check_symbols(char	*str);
int		check_dublicate(t_list *st);
void	free_stack(t_list **stack);
void	checker_bonus(t_list **a, t_list **b);
int		check_space(int argc, char **argv);
int		push_a_bonus(t_list **st, int argc, char **argv);

#endif