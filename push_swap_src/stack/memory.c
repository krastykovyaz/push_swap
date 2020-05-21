/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:49:03 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/18 13:09:29 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	free_stack(t_stack *stack)
{
	t_stack	*prev;

	prev = NULL;
	while (stack->next)
	{
		prev = stack;
		stack = stack->next;
		free(prev);
	}
	free(stack);
}

int		stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

int		have_two(t_stack *stack)
{
	if (stack && stack->next)
		return (1);
	return (0);
}

int		*stack_2_mass(int len, t_stack *a)
{
	int i;
	int	*mass;

	mass = (int*)malloc(sizeof(int) * len);
	if (!mass)
		raise_memory_error();
	i = 0;
	while (i < len)
	{
		mass[i] = a->element;
		i++;
		a = a->next;
	}
	return (mass);
}
