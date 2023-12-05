/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:55:40 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/14 19:59:28 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

t_numb	*add_number(t_numb *pile, char *content)
{
	t_numb	*new_numb;
	t_numb	*aux;

	new_numb = (t_numb *)malloc(sizeof(t_numb));
	if (!new_numb)
		return (NULL);
	new_numb->content = ft_atoi(content);
	new_numb->next = NULL;
	if (!pile)
		return (new_numb);
	aux = pile;
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = new_numb;
	return (pile);
}

void	complete_add_num(t_state *actual_state, int argc, char **argv, int i)
{
	char	**args;

	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = 0;
		while (args[i])
		{
			actual_state->pile_one
				= add_number(actual_state->pile_one, args[i]);
			i++;
		}
		free_argv(args);
	}
	else
	{
		while (i < argc)
		{
			actual_state->pile_one
				= add_number(actual_state->pile_one, argv[i]);
			i++;
		}
	}
}
