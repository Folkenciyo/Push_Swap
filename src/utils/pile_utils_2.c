/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:42:30 by juguerre          #+#    #+#             */
/*   Updated: 2023/10/30 17:50:20 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_find_chipper(t_state *state)
{
	t_numb	*tmp;
	int		chipper;

	tmp = state->pile_two;
	chipper = state->pile_two->final_cost;
	while (tmp)
	{
		if (tmp->final_cost < chipper)
			chipper = tmp->final_cost;
		tmp = tmp->next;
	}
	return (chipper);
}

int	ft_number_to_mov(t_state *state, int chipper)
{
	t_numb	*tmp;

	tmp = state->pile_two;
	while (tmp)
	{
		if (tmp->final_cost == chipper)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (-1);
}

void	ft_reorder_pile_one(t_state *state)
{
	int	num_to_mov_p_1;
	int	num_to_mov_p_2;
	int	chipper;

	chipper = ft_find_chipper(state);
	num_to_mov_p_2 = ft_number_to_mov(state, chipper);
	num_to_mov_p_1 = ft_find_closer(state, num_to_mov_p_2);
	if (!(num_to_mov_p_2 > num_to_mov_p_1
			&& num_to_mov_p_1 == ft_last_num_in_pile_1(state)))
		ft_num_to_top_p_1(state, num_to_mov_p_1);
	ft_num_to_top_p_2(state, num_to_mov_p_2);
	if (num_to_mov_p_2 > num_to_mov_p_1)
	{
		ft_push_a(state);
		if (ft_min(state->pile_one) == state->pile_one->next->content
			&& ft_max(state->pile_one) > ft_last_num_in_pile_1(state))
			ft_rotate_a(state, 0);
		else
			ft_swap_a(state, 0);
	}
	else
	{
		ft_num_to_top_p_1(state, num_to_mov_p_1);
		ft_push_a(state);
	}
}

int	ft_find_index(t_numb *pile, int content)
{
	int		i;

	i = 0;
	while (pile != NULL)
	{
		if (pile->content == content)
		{
			pile->actual_i = i;
			return (i);
		}
		i++;
		pile = pile->next;
	}
	return (-1);
}
