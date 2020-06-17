/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:03:26 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:03:28 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	solve_3(t_stack **a)
{
	int		first;
	int		second;
	int		third;

	first = (*a)->element;
	second = (*a)->next->element;
	third = (*a)->next->next->element;
	if (is_sorted(*a))
		return ;
	else if (first > second && second < third && first < third)
		swap(*a, 'a');
	else if (first > second && second > third && third < first)
	{
		swap(*a, 'a');
		reverse_rotate(&(*a), 'a');
	}
	else if (first > second && second < third && third < first)
		rotate(&(*a), 'a');
	else if (first < second && third < second && third > first)
	{
		swap(*a, 'a');
		rotate(&(*a), 'a');
	}
	else if (first < second && second > third && third < first)
		reverse_rotate(&(*a), 'a');
}
