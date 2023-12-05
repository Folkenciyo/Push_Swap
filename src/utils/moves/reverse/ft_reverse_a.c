/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:18:14 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 23:18:14 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_reverse_rotate_a(t_state *state, int flag)
{
	t_state	*tmp;
	t_state	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (!state->pile_one || !state->pile_one->next)
		return ;
	tmp = allocate_state_memory(tmp);
	tmp2 = allocate_state_memory(tmp);
	tmp->pile_one = state->pile_one;
	tmp2->pile_one = state->pile_one->next;
	while (tmp2->pile_one->next)
	{
		tmp->pile_one = tmp->pile_one->next;
		tmp2->pile_one = tmp2->pile_one->next;
	}
	tmp->pile_one->next = NULL;
	tmp2->pile_one->next = state->pile_one;
	state->pile_one = tmp2->pile_one;
	free(tmp);
	free(tmp2);
	if (flag == 0)
		write_instructions(state, "rra\n");
}
