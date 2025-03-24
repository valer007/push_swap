#include "../include.h"

void print_stack(t_list *st) {
    while (st) {
        ft_printf("%d -> ", st->content);
        st = st->prev;
    }
    ft_printf("NULL\n");
}