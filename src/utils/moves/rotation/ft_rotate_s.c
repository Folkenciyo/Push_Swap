/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:30:21 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 21:30:21 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_rotate_s(t_state *state)
{
	ft_rotate_a(state, 1);
	ft_rotate_b(state, 1);
	write_instructions(state, "rr\n");
}
