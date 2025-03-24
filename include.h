#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdlib.h>
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

void print_stack(t_list *);
void push_a(t_list **, int, char **);
void pa(t_list **, t_list **);
void pb(t_list **, t_list **);
void rra(t_list **);
void rrb(t_list **);
void rrr(t_list **, t_list **);
void ra(t_list **);
void rb(t_list **);
void rr(t_list **, t_list **);
void sa(t_list **);
void sb(t_list **);
void ss(t_list **, t_list **);

int find_min(t_list*);
int find_max(t_list*);
int get_position(t_list *, int);
int get_size(t_list *);
int is_sorted(t_list *);
void sort_three(t_list **);
void sort_five(t_list **, t_list**);
void sort_four(t_list **, t_list **);
void push_swap(t_list **, t_list **, int);
int check_symbols(int, char**);
int check_stack(t_list *);

#endif