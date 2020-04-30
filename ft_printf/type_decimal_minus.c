/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal_minus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:11:38 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:39:49 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	type_decimal_minus_1(t_pr *stut)
{
	if (stut->a < 0)
		ft_putchar('-', stut);
	if (stut->a >= 0 && stut->plus)
		ft_putchar('+', stut);
	else if (stut->a >= 0 && stut->space)
		ft_putchar(' ', stut);
}

int		type_decimal_minus(t_pr *stut)
{
	int i;

	i = 0;
	type_decimal_minus_1(stut);
	if (stut->accuracy > stut->len)
	{
		if (stut->a <= 0)
			i = stut->accuracy - stut->len + 1;
		else
			i = stut->accuracy - stut->len;
	}
	ft_putnchar('0', i, stut);
	if (stut->a >= 0 && (stut->plus || stut->space))
		i++;
	if ((stut->a != 0) || (stut->a == 0 && stut->dot == 0))
	{
		ft_putnbr(convert(stut, 10), stut);
		i = stut->width - i - stut->len;
	}
	else
		i = stut->width - i;
	i > 0 ? ft_putnchar(' ', i, stut) : 0;
	return (0);
}
