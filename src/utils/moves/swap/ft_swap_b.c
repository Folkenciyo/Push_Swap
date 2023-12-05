/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:13:26 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 21:13:26 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_swap_b(t_state *state, int flag)
{
	t_numb	*first;
	t_numb	*second;

	if (!state->pile_one || !state->pile_one->next)
		return ;
	first = state->pile_one;
	second = state->pile_one->next->next;
	state->pile_one = state->pile_one->next;
	first->next = second;
	state->pile_one->next = first;
	if (flag == 0)
		write_instructions(state, "sb\n");
}
