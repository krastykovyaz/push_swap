/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:01:47 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:01:49 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int		is_sorted(t_stack *stack)
{
	t_stack	*prev;

	prev = NULL;
	while (stack)
	{
		if (prev && stack)
			if (stack->element < prev->element)
				return (0);
		prev = stack;
		stack = stack->next;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		ft_strcmp(char *l1, char *l2)
{
	int	i;

	i = 0;
	while (l1[i] != '\0' && l2[i] != '\0')
	{
		if (l1[i] != l2[i])
			return (l2[i] - l1[i]);
		i++;
	}
	return (0);
}

int		is_int(char *str)
{
	int	len;
	int	is_minus;

	is_minus = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		len--;
		is_minus = 1;
		str = str + 1;
	}
	if (len > 10)
		return (0);
	if (len < 10 || str[0] == '+')
		return (1);
	if (is_minus == 1)
	{
		if (ft_strcmp(str, "2147483648") >= 0)
			return (1);
	}
	if (is_minus == 0)
		if (ft_strcmp(str, "2147483647") >= 0)
			return (1);
	return (0);
}
