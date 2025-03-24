#include "../include.h"

void push_a(t_list **st, int argc, char **argv) {
	t_list *new;
	char **str;
	int i;
	int j;
	int count;

	count = 0;
	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		while (str[j])
		{
			new = ft_lstnew(ft_atoi(str[j]), count);
			ft_lstadd_back(st, new);
			count++;
			j++;
		}
		i++;
	}
	free(str);
}