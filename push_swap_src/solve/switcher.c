/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 21:07:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/20 09:51:29 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	manip(int down, int up, t_stack **b, t_pos info)
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

void	wh_loop(int counter, t_stack **a)
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
		manip(down, up, &(*b), info);
		if ((*b)->element == info.min_element)
			if_min = 1;
		push(&(*b), &(*a), 'a');
		if_min ? rotate(&(*a), 'a') : counter++;
	}
	wh_loop(counter, &(*a));
}
