/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juguerre <juguerre@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:47 by juguerre          #+#    #+#             */
/*   Updated: 2023/06/22 21:20:47 by juguerre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_is_sorted(t_numb *pile)
{
	t_numb	*current;

	current = pile;
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_num_is_duplicated(t_numb *pile)
{
	t_numb	*current;
	t_numb	*compared;

	current = pile;
	while (current != NULL)
	{
		compared = current->next;
		while (compared != NULL)
		{
			if (current->content == compared->content)
				return (1);
			compared = compared->next;
		}
		current = current->next;
	}
	return (0);
}

void	ft_is_not_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				write(1, "Error\n", 6);
				exit(2);
			}
			j++;
		}
		i++;
	}
}

void	ft_all_spaces(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == ' ')
		{
			j++;
		}
		if (ft_strlen(argv[i]) == j)
		{
			write(1, "Error\n", 6);
			exit(2);
		}
		i++;
	}
}
