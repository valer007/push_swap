#include "../include.h"

static int rotate(t_list **sta) {
	if(!*sta || !(*sta)->prev) {
		return 0;
	}

	t_list *temp = *sta;
	*sta = (*sta)->prev;
	
	t_list* current = *sta;
	while (current->prev)
		current = current->prev;
	current->prev = temp;
	temp->prev = NULL;
	return 1;
}

void ra(t_list **sta) {
	if (rotate(sta))
	{
		ft_printf("ra\n");
	}
}

void rb(t_list **stb) {
	if (rotate(stb))
	{
		ft_printf("rb\n");
	}
}

void rr(t_list **sta, t_list**stb) {
	if(rotate(sta) && rotate(stb))
		ft_printf("rr");
}