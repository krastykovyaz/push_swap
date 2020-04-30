/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 00:01:45 by ple-thie          #+#    #+#             */
/*   Updated: 2020/04/23 18:38:56 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*ft_itoa2(long long int n)
{
	char			*result;
	int				i;
	long long int	power;
	short			sign;

	sign = (n < 0) ? 2 : 1;
	i = 1;
	power = 1;
	while ((n / power / 10) != 0 && ++i)
		power *= 10;
	if (!(result = malloc(sizeof(char) * (unsigned long)(i + sign))))
		raise_memory_error();
	i = 0;
	if (sign == 2)
		result[i++] = '-';
	while (power)
	{
		result[i++] = n / power * sign + '0';
		n %= power;
		power /= 10;
	}
	result[i++] = '\0';
	return (result);
}
