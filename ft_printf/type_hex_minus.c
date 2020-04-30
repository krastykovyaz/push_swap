/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex_minus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:30:51 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:40:23 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	type_hex_minus_1(const char *format, t_pr *stut)
{
	if (stut->grid && stut->a)
	{
		if (format[stut->i] == 'x')
			ft_putstr("0x", stut);
		else
			ft_putstr("0X", stut);
	}
}

int		type_hex_minus_2(int i, t_pr *stut)
{
	if (i > 0)
		ft_putnchar(' ', i, stut);
	return (0);
}

int		type_hex_minus(const char *format, t_pr *stut)
{
	int	i;

	i = 0;
	type_hex_minus_1(format, stut);
	if (stut->accuracy > stut->len)
	{
		if (stut->a == 0)
			i = stut->accuracy;
		else
			i = stut->accuracy - stut->len;
	}
	ft_putnchar('0', i, stut);
	if (stut->ptr && stut->a)
	{
		ft_putstr(stut->ptr, stut);
		i = stut->width - i - stut->len;
	}
	else if (stut->ptr && stut->a == 0 && !stut->dot)
	{
		ft_putstr(stut->ptr, stut);
		i = stut->width - i - stut->len;
	}
	else
		i = stut->width - i;
	return (type_hex_minus_2(i, stut));
}
