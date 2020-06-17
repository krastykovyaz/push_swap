/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:03:58 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:04:00 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	way_to_b(t_stack **a, t_stack **b, int col_blocks, int len)
{
	int i;
	int step;

	i = 0;
	step = len / col_blocks;
	while (i < (len - step * (col_blocks - 1)))
	{
		push(&(*a), &(*b), 'b');
		i++;
	}
	solve_b(&(*a), &(*b));
}

void	rotation_for_each(t_stack **a, t_stack **b, int step, int k)
{
	int i;

	i = 0;
	while (i < (step * k))
	{
		rotate(&(*a), 'a');
		i++;
	}
	solve_b(&(*a), &(*b));
}

void	transfer_to_b(t_stack **a, t_stack **b, int *mass, int *save)
{
	int i;
	int step;

	step = save[1] / save[0];
	i = 0;
	while (i < save[1])
	{
		if ((*a)->element < mass[step])
			push(&(*a), &(*b), 'b');
		else
			rotate(&(*a), 'a');
		i++;
	}
}

void	depended_push(t_stack **a, t_stack **b, int *save, int *mass)
{
	int step;

	step = save[1] / save[0];
	if ((*a)->element < mass[step * (save[2] + 1)])
		push(&(*a), &(*b), 'b');
	else
		rotate(&(*a), 'a');
}

void	mysolve(t_stack **a, int col_blocks)
{
	t_stack	*b;
	int		len;
	int		*mass;
	int		save[3];
	int		i;

	b = NULL;
	len = stack_len(*a);
	save[0] = col_blocks;
	save[1] = len;
	mass = stack_2_mass(len, *a);
	ft_qsort(len, mass);
	transfer_to_b(&(*a), &b, mass, save);
	solve_b(&(*a), &b);
	save[2] = 1;
	while (save[2] < col_blocks - 1)
	{
		i = 0;
		while (i++ < (len - (len / col_blocks) * save[2]))
			depended_push(&(*a), &b, save, mass);
		rotation_for_each(&(*a), &b, (len / col_blocks), save[2]);
		save[2]++;
	}
	way_to_b(&(*a), &b, col_blocks, len);
	free(mass);
}
