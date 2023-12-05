/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:21:54 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 23:21:54 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_push_b(t_state *state)
{
	t_numb	*tmp_one;
	t_numb	*tmp_two;

	if (!state->pile_one)
		return ;
	if (!state->pile_two)
	{
		state->pile_two = state->pile_one;
		state->pile_one = state->pile_one->next;
		state->pile_two->next = NULL;
		write_instructions(state, "pb\n");
		return ;
	}
	tmp_one = state->pile_one;
	tmp_two = state->pile_two;
	state->pile_one = state->pile_one->next;
	state->pile_two = tmp_one;
	state->pile_two->next = tmp_two;
	write_instructions(state, "pb\n");
}
