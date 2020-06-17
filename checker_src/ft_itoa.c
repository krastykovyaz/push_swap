/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 11:40:59 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/05/28 18:59:27 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/checker.h"

static void	isneg(long long int *nb, int *neg)
{
	if (*nb < 0)
	{
		*nb *= -1;
		*neg = 1;
	}
}

char		*ft_itoas(long long int nb)
{
	int				size;
	int				negative;
	char			*str;
	long long int	n;

	negative = 0;
	size = 2;
	n = nb;
	isneg(&nb, &negative);
	while (n /= 10)
		size++;
	size += negative;
	if ((str = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	str[--size] = '\0';
	while (size--)
	{
		str[size] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
