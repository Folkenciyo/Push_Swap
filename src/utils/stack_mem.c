/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:55:48 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/14 19:55:48 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	free_argv(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_state	*allocate_state_memory(t_state *state)
{
	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (0);
	state->pile_one = NULL;
	state->instructions = NULL;
	return (state);
}

t_numb	*allocate_pile_memory(t_numb *pile)
{
	pile = (t_numb *)malloc(sizeof(t_numb));
	if (!pile)
		return (0);
	pile->next = NULL;
	return (pile);
}

void	free_state_memory(t_state *state)
{
	t_numb	*aux;

	aux = state->pile_one;
	while (aux)
	{
		state->pile_one = aux->next;
		free(aux);
		aux = state->pile_one;
	}
	aux = state->pile_two;
	while (aux)
	{
		state->pile_two = aux->next;
		free(aux);
		aux = state->pile_two;
	}
	free(state);
}
