#include "../include.h"

static int push(t_list **sta, t_list **stb) {
	if(!(*stb)) {
		return 0;
	}

	t_list *temp = (*stb);
	(*stb) = (*stb)->prev;
	temp->prev = *sta;
	*sta = temp;
	return 1;
}

void pa(t_list **sta, t_list**stb) {
	if (push(sta, stb))
		ft_printf("pa\n");
}

void pb(t_list **sta, t_list**stb) {
	if (push(sta, stb))
		ft_printf("pb\n");
}
