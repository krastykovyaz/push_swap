/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switcher3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:44:00 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 21:28:55 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	continue_of_switcher(t_stack **a, int len)
{
	if (len > 120 && len <= 180)
		mysolve(&(*a), 4);
	else if (len > 180 && len <= 300)
		mysolve(&(*a), 5);
	else if (len > 300 && len <= 520)
		mysolve(&(*a), 6);
	else if (len > 520 && len <= 700)
		mysolve(&(*a), 7);
	else if (len > 700 && len <= 880)
		mysolve(&(*a), 8);
	else if (len > 880 && len <= 1120)
		mysolve(&(*a), 9);
	else if (len > 1120 && len <= 1360)
		mysolve(&(*a), 10);
	else if (len > 1360 && len <= 1660)
		mysolve(&(*a), 11);
	else if (len > 1660 && len <= 1960)
		mysolve(&(*a), 12);
	else
		mysolve(&(*a), 13);
}

void	switcher(t_stack *a)
{
	int len;

	len = stack_len(a);
	if (len == 1 || is_sorted(a))
		pass();
	else if (len == 2)
		solve_2(&a);
	else if (len == 3)
		solve_3(&a);
	else if (len == 4)
		solve_4(&a);
	else if (len == 5)
		solve_5(&a);
	else if (len >= 6 && len <= 120)
		mysolve(&a, 3);
	else
		continue_of_switcher(&a, len);
	free_stack(a);
}
