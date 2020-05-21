/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:27:38 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/19 21:06:31 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	pa(t_folder **a, t_folder **b, t_num *count)
{
	t_folder *tmp;

	if (*b)
	{
		tmp = (*b);
		(*b) = (*b)->next;
		tmp->next = NULL;
		if ((*a) == NULL)
			*a = tmp;
		else
		{
			tmp->next = (*a);
			*a = tmp;
		}
		count->c_a++;
		count->c_b--;
	}
}

void	pb(t_folder **a, t_folder **b, t_num *count)
{
	t_folder *tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		if (!*b)
			*b = tmp;
		else
		{
			tmp->next = *b;
			*b = tmp;
		}
		count->c_a--;
		count->c_b++;
	}
}
