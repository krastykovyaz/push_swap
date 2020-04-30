/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:40:59 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:38:51 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*add(long long int n, char *result, int i)
{
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		result[0] = '-';
		n *= (-1);
	}
	while (n > 0)
	{
		result[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
	return (result);
}

char	*ft_itoa(long long int n)
{
	char			*result;
	int				i;
	long long int	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= (-1);
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	if (!(result = (char*)malloc(sizeof(char) * (unsigned long)(i))))
		raise_memory_error();
	result[i--] = '\0';
	result = add(n, result, i);
	return (result);
}
