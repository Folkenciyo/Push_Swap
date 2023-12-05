/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:36:45 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/14 16:50:07 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_three_instruction(int max_mov, int min_mov, t_state *state)
{
	if (min_mov == 0 && max_mov == 1)
	{
		ft_swap_a(state, 0);
		ft_rotate_a(state, 0);
	}
	else if (min_mov == 1 && max_mov == 2)
		ft_swap_a(state, 0);
	else if (min_mov == 2 && max_mov == 1)
		ft_reverse_rotate_a(state, 0);
	else if (max_mov == 0 && min_mov == 1)
		ft_rotate_a(state, 0);
	else if (max_mov == 0 && min_mov == 2)
	{
		ft_rotate_a(state, 0);
		ft_swap_a(state, 0);
	}
}

t_state	*ft_sort_three(t_state *state)
{
	int	min;
	int	max;
	int	min_mov;
	int	max_mov;

	min = ft_min(state->pile_one);
	max = ft_max(state->pile_one);
	min_mov = ft_step_index_moves(state, min);
	max_mov = ft_step_index_moves(state, max);
	ft_sort_three_instruction(max_mov, min_mov, state);
	return (state);
}
