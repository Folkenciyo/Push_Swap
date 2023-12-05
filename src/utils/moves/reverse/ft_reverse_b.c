/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:12:54 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 23:12:54 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_reverse_rotate_b(t_state *state, int flag)
{
	t_state	*tmp;
	t_state	*tmp2;

	tmp = NULL;
	tmp = allocate_state_memory(tmp);
	tmp2 = NULL;
	tmp2 = allocate_state_memory(tmp);
	if (!state->pile_two || !state->pile_two->next)
		return ;
	tmp->pile_two = state->pile_two;
	tmp2->pile_two = state->pile_two->next;
	while (tmp2->pile_two->next)
	{
		tmp->pile_two = tmp->pile_two->next;
		tmp2->pile_two = tmp2->pile_two->next;
	}
	tmp->pile_two->next = NULL;
	tmp2->pile_two->next = state->pile_two;
	state->pile_two = tmp2->pile_two;
	free(tmp);
	free(tmp2);
	if (flag == 0)
		write_instructions(state, "rrb\n");
}
