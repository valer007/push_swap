#include "../include.h"

int find_min(t_list *st) {
	int min;

	min = st->content;
	while (st)
	{
		if(min >= st->content)
			min = st->content;
		st = st->prev;
	}
	return min;
}

int find_max(t_list *st) {
	int max;

	max = st->content;
	while (st)
	{
		if(max <= st->content)
			max = st->content;
		st = st->prev;
	}
	return max;
}

int get_position(t_list *st, int num) {
	int pos;

	pos = 0;
	while(st) {
		if(st->content == num)
			return pos;
		pos++;
		st = st->prev;
	}
	return -1;
}

int get_size(t_list* st) {
	int size;

	size = 0;
	while (st)
	{
		st = st->prev;
		size++;
	}
	return size;
}

int is_sorted(t_list *a) {
	if(!a)
		return 1;

	while (a->prev)
	{
		if (a->content > a->prev->content)
			return 0;
		a = a->prev;
	}
	return 1;
}