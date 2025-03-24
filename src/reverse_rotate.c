#include "../include.h"

static int reverse_rotate(t_list **sta) {
	if(!*sta || !(*sta)->prev)
		return 0;
	
		t_list *temp = *sta;
		while (temp->prev->prev)
		{
			temp = temp->prev;
		}
		t_list *current = temp->prev;
		current->prev = *sta;
		temp->prev = NULL;
		*sta = current;
		return 1;
} 

void rra(t_list **sta) {
	if (reverse_rotate(sta))
	{
		ft_printf("rra\n");
	}
}

void rrb(t_list **stb) {
	if (reverse_rotate(stb))
	{
		ft_printf("rb\n");
	}
}

void rrr(t_list **sta, t_list **stb) {
	if(reverse_rotate(sta) && reverse_rotate(stb)) {
		ft_printf("rrr\n");
	}
}