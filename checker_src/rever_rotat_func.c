/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rever_rotat_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:31:38 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/19 20:59:04 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	rra(t_folder **a)
{
	t_folder *start;
	t_folder *finish;
	t_folder *tmp;

	tmp = *a;
	finish = *a;
	start = *a;
	if (*a)
	{
		while (start->next != NULL)
		{
			start = start->next;
			if (start->next != NULL)
				finish = finish->next;
		}
		if (start->next == NULL)
		{
			start->next = tmp;
			finish->next = NULL;
		}
		*a = start;
	}
}

void	rrb(t_folder **b)
{
	t_folder *x;
	t_folder *y;
	t_folder *z;

	x = *b;
	y = *b;
	z = *b;
	if (*b)
	{
		while (x->next != NULL)
		{
			x = x->next;
			if (x->next != NULL)
				y = y->next;
		}
		if (x->next == NULL)
		{
			x->next = z;
			y->next = NULL;
		}
		(*b) = x;
	}
}

void	rrr(t_folder **a, t_folder **b)
{
	if (*b && *a)
	{
		rra(a);
		rrb(b);
	}
}
