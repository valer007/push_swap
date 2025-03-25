/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:16:04 by vmakarya          #+#    #+#             */
/*   Updated: 2025/03/25 20:17:20 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int argc, char **argv)
{
	t_list	*sta;
	t_list	*stb;
	int		size;

	if (argc < 2)
	{
		ft_printf("Error");
		exit(0);
	}
	sta = NULL;
	stb = NULL;
	push_a(&sta, argc, argv);
	if (!check_symbols(argc, argv) || !check_stack(sta))
	{
		ft_printf("Error");
		exit(0);
	}
	size = get_size(sta);
	push_swap(&sta, &stb, size);
}
