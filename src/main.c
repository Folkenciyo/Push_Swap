/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:30:21 by juguerre          #+#    #+#             */
/*   Updated: 2023/05/29 13:30:23 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	start_solving(t_state *state)
{
	if (!state->pile_one)
		return ;
	state->max_size = ft_pile_size(state->pile_one);
	if (ft_num_is_duplicated(state->pile_one))
	{
		ft_printf("Error\n");
		exit(2);
	}
	else if (!ft_is_sorted(state->pile_one))
	{
		ft_sort(state);
	}
}

int	state_constructor(t_state *actual_state, int argc, char **argv)
{
	int		i;

	i = 1;
	complete_add_num(actual_state, argc, argv, i);
	return (i);
}

int	main(int argc, char **argv)
{
	t_state	*state;
	t_state	*actual_state;
	int		i;

	if (argc == 1)
		exit(0);
	ft_is_not_digit(argc, argv);
	ft_all_spaces(argc, argv);
	actual_state = NULL;
	actual_state = allocate_state_memory(actual_state);
	state = actual_state;
	i = state_constructor(actual_state, argc, argv);
	actual_state->max_size = i - 1;
	start_solving(state);
	print_instructions(state);
	free_instructions(state);
	free_state_memory(state);
	exit (0);
}
