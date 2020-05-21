/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:41:43 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/20 13:26:37 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	w_loop(t_stack **a, t_stack **b, int col_blocks, int len)
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

void	fori(t_stack **a, t_stack **b, int step, int k)
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

void	whi_loop(t_stack **a, t_stack **b, int *mass, int *save)
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

void	el_if(t_stack **a, t_stack **b, int *save, int *mass)
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
	whi_loop(&(*a), &b, mass, save);
	solve_b(&(*a), &b);
	save[2] = 1;
	while (save[2] < col_blocks - 1)
	{
		i = 0;
		while (i++ < (len - (len / col_blocks) * save[2]))
			el_if(&(*a), &b, save, mass);
		fori(&(*a), &b, (len / col_blocks), save[2]);
		save[2]++;
	}
	w_loop(&(*a), &b, col_blocks, len);
	free(mass);
}
