/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:19:26 by juguerre          #+#    #+#             */
/*   Updated: 2023/11/15 20:29:21 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_pile(t_numb *pile, char *str)
{
	t_numb	*tmp;

	tmp = pile;
	while (tmp)
	{
		printf("%s = %d\n", str, tmp->content);
		tmp = tmp->next;
	}
}

int	ft_flag(t_state *state)
{
	t_numb	*tmp;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	tmp = state->pile_one;
	while (tmp)
	{
		if (tmp->content != ft_min(state->pile_one))
		{
			i++;
		}
		tmp = tmp->next;
	}
	if (i > (ft_pile_size(state->pile_one) / 2))
		flag = 1;
	else
		flag = -1;
	return (flag);
}

void	ft_sort_big(t_state *state)
{
	t_numb	*pile_two;
	int		flag;

	flag = 0;
	pile_two = NULL;
	state->pile_two = pile_two;
	while (ft_pile_size(state->pile_one) > 3)
		ft_send_all_to_b(state);
	ft_sort_three(state);
	while (ft_pile_size(state->pile_one) != state->max_size)
	{
		ft_calculate_pos(state);
		ft_reorder_pile_one(state);
	}
	flag = ft_flag(state);
	while (!(ft_min(state->pile_one) == state->pile_one->content))
	{
		if (flag == -1)
			ft_rotate_a(state, 0);
		else
			ft_reverse_rotate_a(state, 0);
	}
}
