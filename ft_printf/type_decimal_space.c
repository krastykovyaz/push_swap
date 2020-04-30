/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:21:58 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/24 20:09:06 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	decimal_space_if_1(int y, t_pr *stut)
{
	if (stut->accuracy && stut->accuracy > stut->len)
		ft_putnchar(' ', stut->width - stut->accuracy + 1, stut);
	else if (stut->accuracy && stut->width > stut->len && stut->zero)
		ft_putnchar(' ', stut->width - stut->accuracy, stut);
	else if (stut->accuracy && stut->zero)
		ft_putnchar(' ', stut->width - stut->accuracy + 1, stut);
	else if (stut->accuracy && stut->accuracy < stut->len)
	{
		if (stut->width == stut->accuracy && \
		stut->accuracy < stut->len && stut->width < stut->len)
			ft_putchar(' ', stut);
		ft_putnchar(' ', stut->width - y, stut);
	}
	else if (!stut->accuracy && stut->width > stut->len && stut->zero)
		ft_putchar(' ', stut);
	else if (!stut->accuracy && stut->width > stut->len)
		ft_putnchar(' ', (stut->width - stut->len + 1), stut);
	else if (!stut->accuracy && stut->width < stut->len)
		ft_putnchar(' ', (stut->width - stut->len + 2), stut);
	else if (stut->accuracy < stut->width)
		ft_putnchar(' ', (stut->width - stut->len + 1), stut);
	else if (stut->width <= stut->len)
		ft_putchar(' ', stut);
}

void	decimal_space_if(const char *format, int y, t_pr *stut)
{
	if ((stut->len > stut->width || \
	stut->accuracy > stut->width) && format[stut->i] != 'u')
		ft_putchar(' ', stut);
	stut->width -= 1;
	if (stut->width >= stut->accuracy)
		decimal_space_if_1(y, stut);
}

void	decimal_space_else(t_pr *stut)
{
	if (stut->width > stut->accuracy)
	{
		if (stut->accuracy > stut->len)
			ft_putnchar(' ', stut->width - stut->accuracy - 1, stut);
		else if (stut->accuracy || (!stut->zero && stut->width > stut->len))
			ft_putnchar(' ', stut->width - stut->len, stut);
	}
	ft_putchar('-', stut);
	stut->a *= (-1);
}

int		type_decimal_space_1(int i, int y, t_pr *stut)
{
	if (stut->width != 0 && stut->accuracy > 0 && \
	stut->accuracy > stut->len && stut->a > 0)
		i = y;
	else if (stut->accuracy > 0 && stut->accuracy > stut->len)
	{
		if (stut->len == 1)
			i = y - 1;
		else
			i = y;
	}
	if (i != 0)
		ft_putnchar('0', i, stut);
	else if (stut->zero && ((convert(stut, 10) == 0) || \
	(stut->width > stut->len && !stut->accuracy)))
		ft_putnchar('0', stut->width - stut->len, stut);
	ft_putnbr(convert(stut, 10), stut);
	return (0);
}

int		type_decimal_space(const char *format, t_pr *stut)
{
	int i;
	int y;

	y = 0;
	i = 0;
	if (stut->accuracy > stut->len)
		y = stut->accuracy - stut->len;
	else
		y = stut->accuracy;
	if (stut->a <= 0)
		y = y + 1;
	if (stut->a >= 0)
		decimal_space_if(format, y, stut);
	else
		decimal_space_else(stut);
	return (type_decimal_space_1(i, y, stut));
}
