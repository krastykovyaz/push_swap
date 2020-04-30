/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal_plus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:13:54 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:39:53 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		decimal_plus_space(t_pr *stut)
{
	int i;

	i = 0;
	if (stut->width > stut->len && stut->width > stut->accuracy)
	{
		if (stut->accuracy > stut->len)
		{
			if (stut->a <= 0)
			{
				i = stut->width - stut->accuracy - 1;
			}
			else
				i = stut->width - stut->accuracy;
		}
		else
			i = stut->width - stut->len;
		if (stut->a >= 0 && (stut->plus || stut->space))
			i--;
		if (stut->a == 0 && stut->dot == 1)
			i++;
		if (!stut->zero || stut->dot)
			ft_putnchar(' ', i, stut);
	}
	return (i);
}

int		type_decimal_plus(const char *format, t_pr *stut)
{
	int i;

	i = decimal_plus_space(stut);
	if (stut->a < 0 && format[stut->i] != 'u')
		ft_putchar('-', stut);
	if (stut->a >= 0 && stut->plus && format[stut->i] != 'u')
		ft_putchar('+', stut);
	else if (stut->a >= 0 && stut->space && format[stut->i] != 'u')
		ft_putchar(' ', stut);
	if (stut->zero && !stut->dot)
		ft_putnchar('0', i, stut);
	if (stut->accuracy > stut->len)
	{
		if (stut->a <= 0)
		{
			i = stut->accuracy - stut->len + 1;
		}
		else
			i = stut->accuracy - stut->len;
		if (i > 0)
			ft_putnchar('0', i, stut);
	}
	if (stut->a != 0 || (stut->a == 0 && stut->dot == 0))
		ft_putnbr(convert(stut, 10), stut);
	return (0);
}
