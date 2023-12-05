/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:12:03 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 23:12:03 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_reverse_rotate_s(t_state *state)
{
	ft_reverse_rotate_a(state, 1);
	ft_reverse_rotate_b(state, 1);
	write_instructions(state, "rrr\n");
}
