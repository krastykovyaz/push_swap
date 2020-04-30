/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal_regular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:15:23 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/25 22:26:47 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	decimal_pregular_zero(int i, t_pr *ssl)
{
	if (ssl->a < 0)
		i = ssl->accuracy - ssl->len + 1;
	else
		i = ssl->accuracy - ssl->len;
	ft_putnchar('0', i, ssl);
}

int		type_decimal_regular(t_pr *stut)
{
	int i;

	i = decimal_pregular_space(stut);
	if (stut->a < 0)
		ft_putchar('-', stut);
	if (stut->accuracy >= stut->len)
		decimal_pregular_zero(i, stut);
	stut->a = stut->a < 0 ? (stut->a * (-1)) : stut->a;
	if (stut->a != 0 || (stut->a == 0 && stut->accuracy > 1))
	{
		if (stut->a == -1 * 9223372036854775808ull)
			ft_putstr("9223372036854775808", stut);
		else
			ft_putnbr(convert(stut, 10), stut);
	}
	if (stut->a == 0)
	{
		if (stut->width >= 0 && stut->accuracy == 0 && stut->dot == 0)
			ft_putchar('0', stut);
		else if (stut->width != 0 && stut->accuracy == 0 && stut->dot == 1)
			ft_putchar(' ', stut);
	}
	return (0);
}
