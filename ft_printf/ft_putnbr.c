/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:34:45 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/25 13:59:41 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_putnbr(__int128_t n, t_pr *stut)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", stut);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-', stut);
	}
	if (n > 9)
		ft_putnbr(n / 10, stut);
	ft_putchar(n % 10 + '0', stut);
}
