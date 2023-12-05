/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:13:12 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 21:13:12 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

void	ft_swap_ss(t_state *state)
{
	ft_swap_a(state, 1);
	ft_swap_b(state, 1);
	write_instructions(state, "ss\n");
}
