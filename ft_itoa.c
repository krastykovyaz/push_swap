/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:40:59 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/30 10:27:25 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

char *ft_itoaS(long long int n)
{
	char *result;
	int sign;
	int power;
	int i;

	i = 1;
	sign = 1;
	if (n < 0)
		sign = -1;
	power = 1;
	while (n / 10 / power != 0 && ++i)
		power = power * 10;
	if (!(result = malloc(sizeof(char) * (unsigned long)(i + sign + 1))))
		return (NULL);
	i = 0;
	if (sign == -1)
    {
		result[i++] = '-';
        sign = -1;
    }
    
	while (power != 0)
	{
		result[i] = (char)((int)n * sign / power + '0');
		n = n % power;
		power =power / 10;
        i++;
	}
	result[i++] = '\0';
	return (result);
}
