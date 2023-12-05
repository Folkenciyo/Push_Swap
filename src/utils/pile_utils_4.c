/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:33:01 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/15 20:29:11 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_send_all_to_b(t_state *state)
{
	t_numb	*tmp;
	int		i;
	int		content;

	tmp = state->pile_one;
	i = 0;
	content = state->pile_one->content;
	while (tmp->next)
	{
		if (content > tmp->next->content)
			i++;
		tmp = tmp->next;
	}
	if (i >= ft_pile_size(state->pile_one) / 2)
		ft_push_b(state);
	else
		ft_rotate_a(state, 0);
}

int	ft_last_num_in_pile_1(t_state *state)
{
	t_numb	*tmp;

	tmp = state->pile_one;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}

int	ft_last_num_in_pile_2(t_state *state)
{
	t_numb	*tmp;

	tmp = state->pile_two;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->content);
}

void	ft_num_to_top_1(t_state *state, int num_to_mov, int i)
{
	if (i > (ft_pile_size(state->pile_one) / 2))
	{
		while (state->pile_one->content != num_to_mov)
		{
			ft_reverse_rotate_a(state, 0);
		}
	}
	else
	{
		while (state->pile_one->content != num_to_mov)
		{
			ft_rotate_a(state, 0);
		}
	}
}
