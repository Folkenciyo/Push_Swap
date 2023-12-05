/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:22:52 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 23:22:52 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_push_a(t_state *state)
{
	t_numb	*tmp_one;
	t_numb	*tmp_two;

	if (!state->pile_two)
		return ;
	if (!state->pile_one)
	{
		state->pile_one = state->pile_two;
		state->pile_two = state->pile_two->next;
		state->pile_one->next = NULL;
		write_instructions(state, "pa\n");
		return ;
	}
	tmp_one = state->pile_one;
	tmp_two = state->pile_two;
	state->pile_two = state->pile_two->next;
	state->pile_one = tmp_two;
	state->pile_one->next = tmp_one;
	write_instructions(state, "pa\n");
}
