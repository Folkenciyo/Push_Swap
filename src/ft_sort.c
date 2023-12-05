/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_condition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:29:48 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/18 15:29:51 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_step_index_moves(t_state *state, int num)
{
	int		i;
	int		j;
	t_numb	*actual;

	i = 0;
	j = 0;
	actual = state->pile_one;
	while (actual)
	{
		if (actual->content == num)
			i = j;
		j++;
		actual = actual->next;
	}
	if (i == state->max_size)
		return (i);
	if (i > (state->max_size / 2) && state->max_size != 3)
		i = state->max_size - i;
	return (i);
}

void	ft_sort(t_state *state)
{
	if (state->max_size == 2)
		ft_swap_a(state, 0);
	else if (state->max_size == 3)
		ft_sort_three(state);
	else
		ft_sort_big(state);
}
