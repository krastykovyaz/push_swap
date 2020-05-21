/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:14:56 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/18 12:51:10 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		ft_atoi(const char *str)
{
	int		number;
	int		sign;

	number = 0;
	sign = 1;
	if (*str != '\0')
	{
		while ((*str >= '\t' && *str <= '\r') || *str == ' ')
			str++;
		if (*str == '+' || *str == '-')
		{
			sign = (*str == '-') ? -1 : 1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			number = number * 10 + sign * (*str - '0');
			str++;
		}
	}
	return (number);
}
