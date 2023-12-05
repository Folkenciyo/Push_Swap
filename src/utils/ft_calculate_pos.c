/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:50:30 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/14 16:49:03 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_cal_cost_a(t_state *state, int pile2_content)
{
	int		i;
	t_numb	*tmp;
	int		nearest;

	i = 0;
	tmp = state->pile_one;
	nearest = state->pile_one->content;
	while (tmp)
	{
		if (ft_abs(tmp->content - pile2_content)
			< ft_abs(nearest - pile2_content))
			nearest = tmp->content;
		tmp = tmp->next;
	}
	if (pile2_content > ft_max(state->pile_one))
		return (0);
	i = ft_step_index_moves(state, nearest);
	return (i);
}

void	ft_calculate_pos(t_state *state)
{
	t_numb	*tmp;

	tmp = state->pile_two;
	while (tmp)
	{
		tmp->actual_i = ft_find_index(state->pile_two, tmp->content);
		if (tmp->actual_i > (ft_pile_size(state->pile_two) / 2))
			tmp->cost_b = tmp->actual_i / 2;
		else
			tmp->cost_b = tmp->actual_i;
		tmp->cost_a = ft_cal_cost_a(state, tmp->content);
		tmp->final_cost = tmp->cost_a + tmp->cost_b;
		tmp = tmp->next;
	}
}
