#include "../include.h"

int check_symbols(int argc, char **argv) {
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
			j = 0;
			while (argv[i][j])
			{
				if(argv[i][j] >= '0' && argv[i][j] <= '9')
					j++;
				else 
					return (0);
			}
		i++;
	}
	return (1);
}

int check_stack(t_list *a) {
	t_list *temp = a;
	while (temp)
	{
		t_list *node = a;
		while (node != temp)
		{
			if (temp->content == node->content)
				return 0;
			node = node->prev;
		}
		temp = temp->prev;
	}
	return (1);
}