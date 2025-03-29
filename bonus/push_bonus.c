#include "push_swap_bonus.h"

static int	push(t_list **sta, t_list **stb)
{
	t_list	*temp;

	if (!(*stb))
		return (0);
	temp = (*stb);
	(*stb) = (*stb)->prev;
	temp->prev = *sta;
	*sta = temp;
	return (1);
}

void	pa(t_list **sta, t_list **stb)
{
	push(sta, stb);
}

void	pb(t_list **sta, t_list **stb)
{
	push(sta, stb);
}