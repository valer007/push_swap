#include "../include.h"

static int swap(t_list **st){
	if(!(*st)->prev || !(*st)) {
		return 0;
	}

	t_list *tmp;
    tmp = *st;
    *st = (*st)->prev;
    tmp->prev = (*st)->prev;
    (*st)->prev = tmp;
	return 1;
}

void sa(t_list **sta) {
	if(swap(sta))
		ft_printf("%s\n", "sa");
}

void sb(t_list **stb) {
	if(swap(stb))
		ft_printf("%s\n", "sb");
}

void ss(t_list **sta, t_list **stb) {
	if(swap(sta) && swap(stb)) 
		ft_printf("%s\n", "ss");
}