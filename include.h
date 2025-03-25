/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:47:50 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/25 20:27:24 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	print_stack(t_list *st);
void	push_a(t_list **sta, int argc, char **argv);
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
int		check_symbols(int argc, char **argv);
int		check_stack(t_list *st);

#endif