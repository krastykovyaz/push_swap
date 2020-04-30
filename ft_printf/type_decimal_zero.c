/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal_zero.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:27:37 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/24 20:07:56 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	decimal_pzero_1(int i, t_pr *stut)
{
	if (stut->accuracy)
		ft_putnchar(' ', i, stut);
	else
	{
		if (stut->a < 0)
			ft_putchar('-', stut);
		ft_putnchar('0', i, stut);
	}
}

int		decimal_pzero(t_pr *stut)
{
	int i;

	i = 0;
	if ((stut->width > stut->len) || stut->space)
	{
		if (stut->accuracy >= stut->len)
		{
			i = stut->width - stut->accuracy;
			i = (stut->a < 0) ? i - 1 : i;
		}
		else
			i = stut->width - stut->len;
		if (i >= 0)
			decimal_pzero_1(i, stut);
		else if (stut->space)
			ft_putchar(' ', stut);
	}
	return (i);
}

int		type_decimal_zero(t_pr *stut)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	decimal_pzero(stut);
	if (stut->width > stut->len && i >= 0 && stut->a < 0 && !stut->accuracy)
		m = 1;
	if (stut->a < 0 && m == 0)
		ft_putchar('-', stut);
	if (stut->accuracy >= stut->len)
	{
		i = stut->accuracy - stut->len;
		i = (stut->a < 0) ? 1 + i : i;
		ft_putnchar('0', i, stut);
	}
	ft_putnbr(convert(stut, 10), stut);
	return (0);
}
