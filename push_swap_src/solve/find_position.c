/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:41:10 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/20 19:22:14 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_pos	get_position_info(t_stack *stack)
{
	int		i;
	t_pos	info;

	info.min_position = 0;
	info.max_position = 0;
	info.min_element = stack->element;
	info.max_element = stack->element;
	i = 0;
	while (stack)
	{
		if (stack->element < info.min_element)
		{
			info.min_element = stack->element;
			info.min_position = i;
		}
		if (stack->element > info.max_element)
		{
			info.max_element = stack->element;
			info.max_position = i;
		}
		i++;
		stack = stack->next;
	}
	info.len = i;
	return (info);
}
