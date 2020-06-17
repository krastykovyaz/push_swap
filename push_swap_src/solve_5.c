/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:03:45 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:03:47 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	move_one_smaller(t_stack **a, t_stack **b)
{
	int		i;
	t_pos	info;

	info = get_position_info(*a);
	i = 0;
	if (info.min_position <= 3)
	{
		while (i < info.min_position)
		{
			rotate(&(*a), 'a');
			i++;
		}
	}
	else
		while (i < (5 - info.min_position))
		{
			reverse_rotate(&(*a), 'a');
			i++;
		}
	push(&(*a), &(*b), 'b');
}

void	move_two_smaller(t_stack **a, t_stack **b)
{
	move_one_smaller(&(*a), &(*b));
	move_one_smaller(&(*a), &(*b));
}

void	solve_5(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	move_two_smaller(&(*a), &b);
	solve_3(&(*a));
	push(&b, &(*a), 'a');
	push(&b, &(*a), 'a');
}
