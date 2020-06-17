/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:03:01 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:03:03 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

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
