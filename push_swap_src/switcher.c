/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:03:52 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:03:54 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	choose_side(int down, int up, t_stack **b, t_pos info)
{
	int i;

	i = 0;
	if ((info.len - down) >= up)
		while (i++ < up)
			rotate(&(*b), 'b');
	else
		while (i++ < (info.len - down))
			reverse_rotate(&(*b), 'b');
}

void	put_to_bottom(int counter, t_stack **a)
{
	int i;

	i = 0;
	i = 0;
	while (i++ < counter)
		rotate(&(*a), 'a');
}

void	solve_b(t_stack **a, t_stack **b)
{
	int		if_min;
	int		counter;
	int		up;
	int		down;
	t_pos	info;

	counter = 0;
	while (*b)
	{
		info = get_position_info(*b);
		up = info.min_position <= info.max_position ? \
		info.min_position : info.max_position;
		down = up == info.max_position ? info.min_position : info.max_position;
		if_min = 0;
		choose_side(down, up, &(*b), info);
		if ((*b)->element == info.min_element)
			if_min = 1;
		push(&(*b), &(*a), 'a');
		if_min ? rotate(&(*a), 'a') : counter++;
	}
	put_to_bottom(counter, &(*a));
}
