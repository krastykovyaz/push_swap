/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_octal_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:38:59 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:40:45 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		type_octal_zero_1(int i, t_pr *stut)
{
	if (i > 0)
		ft_putnchar('0', i, stut);
	ft_putnbr(stut->a, stut);
	return (0);
}

int		type_octal_zero(t_pr *stut)
{
	int i;

	i = 0;
	if (stut->width > stut->len)
	{
		if (stut->accuracy >= stut->len)
			i = stut->width - stut->accuracy;
		else
			i = stut->width - stut->len;
		if (stut->grid && stut->width <= stut->len + i)
			i -= 1;
		if (i >= 0 && stut->dot)
			ft_putnchar(' ', i, stut);
		else if (i >= 0)
			ft_putnchar('0', i, stut);
	}
	if (stut->grid && (i == 0 || (i + stut->len < stut->width)))
		ft_putchar('0', stut);
	if (stut->accuracy > stut->len)
		i = stut->accuracy - stut->len;
	else
		i = 0;
	if (stut->grid)
		i -= 1;
	return (type_octal_zero_1(i, stut));
}
