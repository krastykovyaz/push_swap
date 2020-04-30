/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_octal_regular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:36:48 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:40:38 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		type_octal_regular_1(t_pr *stut)
{
	if (stut->a != 0 || (stut->a == 0 && stut->accuracy > 1))
		ft_putnbr(stut->a, stut);
	if (stut->a == 0 && !stut->grid)
	{
		if (stut->width >= 0 && stut->accuracy == 0 && stut->dot == 0)
			ft_putchar('0', stut);
		else if (stut->width != 0 && stut->dot == 1 && stut->accuracy == 0)
			ft_putchar(' ', stut);
	}
	return (0);
}

int		type_octal_regular(t_pr *stut)
{
	int	i;

	i = 0;
	if (stut->width > stut->len)
	{
		if (stut->accuracy >= stut->len)
			i = stut->width - stut->accuracy;
		else
			i = stut->width - stut->len;
		if (stut->grid && stut->a != 0 && stut->width <= stut->len + i)
			i -= 1;
		if (i >= 0)
			ft_putnchar(' ', i, stut);
	}
	if (stut->accuracy >= stut->len)
	{
		i = stut->accuracy - stut->len;
		ft_putnchar('0', i, stut);
	}
	if (stut->grid && stut->accuracy <= stut->len)
		ft_putchar('0', stut);
	if (stut->a < 0)
		stut->a *= (-1);
	return (type_octal_regular_1(stut));
}
