/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:56:29 by juguerre          #+#    #+#             */
/*   Updated: 2023/10/30 17:49:52 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_find_closer(t_state *state, int num_to_mov)
{
	t_numb	*tmp;
	int		closer;
	int		distance;
	int		new_distance;

	tmp = state->pile_one;
	closer = tmp->content;
	distance = ft_abs(num_to_mov - state->pile_one->content);
	while (tmp)
	{
		new_distance = ft_abs(num_to_mov - tmp->content);
		if (new_distance < distance && new_distance > 0)
		{
			distance = new_distance;
			closer = tmp->content;
		}
		tmp = tmp->next;
	}
	return (closer);
}

void	ft_num_to_top_2(t_state *state, int num_to_mov, int i)
{
	if (i > (ft_pile_size(state->pile_two) / 2))
	{
		while (state->pile_two->content != num_to_mov)
			ft_reverse_rotate_b(state, 0);
	}
	else
	{
		while (state->pile_two->content != num_to_mov)
			ft_rotate_b(state, 0);
	}
}

void	ft_num_to_top_p_2(t_state *state, int num_to_mov)
{
	int		i;
	t_numb	*tmp;

	i = 0;
	tmp = state->pile_two;
	while (tmp->content != num_to_mov)
	{
		i++;
		tmp = tmp->next;
	}
	ft_num_to_top_2(state, num_to_mov, i);
}

void	ft_num_to_top_p_1(t_state *state, int num_to_mov)
{
	int		i;
	t_numb	*tmp;

	i = 0;
	tmp = state->pile_one;
	while (tmp->content != num_to_mov)
	{
		i++;
		tmp = tmp->next;
	}
	ft_num_to_top_1(state, num_to_mov, i);
}
