#include "../include.h"

static int	optimaizer(int size)
{
	int	sqrt;
	int	log;

	sqrt = 1;
	log = 0;
	while (sqrt < size / sqrt)
		sqrt++;
	while (size)
	{
		size /= 2;
		log++;
	}
	return (sqrt + log - 1);
}

void push_swap(t_list **a, t_list **b, int size) {
	if (is_sorted(*a))
		return;
	else if (size == 2) 
		return (sa(a));
	else if(size == 3)
		return (sort_three(a));
	else if(size == 4)
		return (sort_four(a, b));
	else if (size == 5)
		return (sort_five(a, b));

	int counter = 0;
	int n = optimaizer(size);

	if(size <= 100) {
		n = 15;
	} else if(size <= 500) {
		n = 30;
	}
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(b, a);
			rb(b);
			counter++;
		} else if((*a)->index <= counter + n) {
			pb(b, a);
			counter++;
		} else {
			ra(a);
		}
	}

	while (*b) {
        int max_pos = get_position(*b, find_max(*b));
        if (max_pos <= get_size(*b) / 2) {
            while (max_pos-- > 0)
                rb(b);
        } else {
            while (max_pos++ < get_size(*b))
                rrb(b);
        }
        pa(a, b);
    }
}
