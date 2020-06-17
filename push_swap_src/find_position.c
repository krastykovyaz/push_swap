/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:02:13 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:02:15 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

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
