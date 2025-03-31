/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:47:50 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/31 13:21:27 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

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

#endif