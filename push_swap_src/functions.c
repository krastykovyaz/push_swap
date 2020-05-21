/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 18:22:46 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/18 12:40:55 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

void	swap(t_stack *stack, char act)
{
	int	tmp;

	if (!have_two(stack))
		return ;
	tmp = stack->element;
	stack->element = (stack->next)->element;
	(stack->next)->element = tmp;
	write(1, "s", 1);
	write(1, &act, 1);
	write(1, "\n", 1);
}

void	push(t_stack **rem_head, t_stack **get_head, char act)
{
	if (!get_head || !rem_head)
		return ;
	append_head(get_head, delete_element(rem_head, 0));
	write(1, "p", 1);
	write(1, &act, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack **stack, char act)
{
	if (!have_two(*stack))
		return ;
	append_element(delete_head(&(*stack)), *stack);
	write(1, "r", 1);
	write(1, &act, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack **stack, char act)
{
	if (!have_two(*stack))
		return ;
	append_head(&(*stack), delete_last(*stack));
	write(1, "rr", 2);
	write(1, &act, 1);
	write(1, "\n", 1);
}
