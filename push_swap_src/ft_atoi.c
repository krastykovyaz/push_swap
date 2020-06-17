/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:02:21 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:02:23 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

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
