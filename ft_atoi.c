/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:29:16 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/30 10:15:34 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

#include <stdio.h>

__int128_t ft_atoiS(const char *s)
{
	__int128_t nb;
	int         i;
	int         sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' ||\
	s[i] == '\f' || s[i] == '\n')
		i++;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i] >= '0' && s[i] < '9')
	{
		nb = nb * 10 + (s[i] - '0');
		i++;
	}
	return (nb *sign);
}

int main()
{
    printf("%s\n", "-1234");
}