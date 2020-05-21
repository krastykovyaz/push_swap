/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_order.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:14:15 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/16 00:38:50 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

void	free_st(t_folder **a, t_folder **b)
{
	t_folder *tmp;

	while (*a)
	{
		tmp = (*a);
		tmp->data = 0;
		*a = (*a)->next;
		free(tmp);
	}
	while (*b)
	{
		tmp = (*b);
		tmp->data = 0;
		*b = (*b)->next;
		free(tmp);
	}
}

void	ch_order(t_folder **a, t_num *count)
{
	int			flag;
	t_folder	*tmp;

	flag = 0;
	tmp = *a;
	if (count->c_b)
		flag = 1;
	while (tmp && tmp->next)
	{
		if (tmp->next)
			if (tmp->data > tmp->next->data)
				flag = 1;
		tmp = tmp->next;
	}
	if (flag)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
