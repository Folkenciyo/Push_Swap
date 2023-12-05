/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/06/18 15:28:16 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/18 15:28:25 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/push_swap.h"

t_instruction	*add_new_instruction(char *str)
{
	t_instruction	*new_instruction;

	new_instruction = malloc(sizeof(t_instruction));
	if (!new_instruction)
		return (NULL);
	new_instruction->line = str;
	new_instruction->next = NULL;
	return (new_instruction);
}

void	write_instructions(t_state *state, char *instruction)
{
	t_instruction	*new_instruction;
	t_instruction	*tmp_instruction;

	if (!state)
		return ;
	if (!state->instructions)
	{
		state->instructions = add_new_instruction(ft_strdup(instruction));
		return ;
	}
	tmp_instruction = state->instructions;
	new_instruction = add_new_instruction(ft_strdup(instruction));
	if (!new_instruction)
		return ;
	while (tmp_instruction->next)
		tmp_instruction = tmp_instruction->next;
	tmp_instruction->next = new_instruction;
}

void	print_instructions(t_state *state)
{
	t_instruction	*actual_instruction;

	actual_instruction = state->instructions;
	while (actual_instruction)
	{
		ft_printf("%s", actual_instruction->line);
		actual_instruction = actual_instruction->next;
	}
}

void	free_instructions(t_state *state)
{
	t_instruction	*actual_instruction;
	t_instruction	*tmp_instruction;

	actual_instruction = state->instructions;
	while (actual_instruction)
	{
		tmp_instruction = actual_instruction->next;
		free(actual_instruction->line);
		free(actual_instruction);
		actual_instruction = tmp_instruction;
	}
}
