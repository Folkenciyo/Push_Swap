/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:29:33 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 21:29:33 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_rotate_a(t_state *state, int flag)
{
	t_state	*tmp;
	t_state	*tmp2;

	tmp = NULL;
	tmp = allocate_state_memory(tmp);
	tmp2 = NULL;
	tmp2 = allocate_state_memory(tmp);
	if (!state->pile_one || !state->pile_one->next)
		return ;
	tmp->pile_one = state->pile_one;
	tmp2->pile_one = state->pile_one->next;
	while (tmp->pile_one->next)
		tmp->pile_one = tmp->pile_one->next;
	tmp->pile_one->next = state->pile_one;
	state->pile_one->next = NULL;
	state->pile_one = tmp2->pile_one;
	free(tmp);
	free(tmp2);
	if (flag == 0)
		write_instructions(state, "ra\n");
}
