#include "include.h"

int main(int argc, char **argv) {
	if(argc < 2) {
		ft_printf("Error");
		exit(0);
	}
	t_list *sta = NULL;
	t_list *stb = NULL;
	push_a(&sta, argc, argv);
	if (!check_symbols(argc, argv) || !check_stack(sta)) {
		ft_printf("Error");
		exit(0);
	}
	// print_stack(sta);
	int size = get_size(sta);
	push_swap(&sta, &stb, size);
	// print_stack(sta);
}