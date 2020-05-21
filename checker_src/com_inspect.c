/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_inspect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 21:17:55 by lnoisome          #+#    #+#             */
/*   Updated: 2020/05/19 20:36:09 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

int		com_inspect1(t_folder **a, t_folder **b,
		char *line, int i)
{
	if (i == 2 && line[0] == 'r' && line[1] == 'b')
		rb(b);
	else if (i == 2 && line[0] == 'r' && line[1] == 'r')
		rr(a, b);
	else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
		rra(a);
	else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
		rrb(b);
	else if (i == 3 && line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
		rrr(a, b);
	else
		return (1);
	return (0);
}

int		com_inspect(t_folder **a, t_folder **b, char *line, t_num *count)
{
	int i;

	i = ft_strlen(line);
	if (i == 2 && line[0] == 's' && line[1] == 'a')
		sa(a);
	else if (i == 2 && line[0] == 's' && line[1] == 'b')
		sb(b);
	else if (i == 2 && line[0] == 's' && line[1] == 's')
		ss(a, b);
	else if (i == 2 && line[0] == 'p' && line[1] == 'a')
		pa(a, b, count);
	else if (i == 2 && line[0] == 'p' && line[1] == 'b')
		pb(a, b, count);
	else if (i == 2 && line[0] == 'r' && line[1] == 'a')
		ra(a);
	else if (com_inspect1(a, b, line, i))
		return (1);
	return (0);
}
