/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 21:01:16 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:38:26 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		float_minus(t_pr *stut)
{
	int	i;

	i = 0;
	if (stut->fl >= 0 && (stut->plus || stut->space))
	{
		if (stut->plus)
			ft_putchar('+', stut);
		if (stut->space)
			ft_putchar(' ', stut);
		i++;
	}
	if (stut->fl < 0)
	{
		ft_putchar('-', stut);
		stut->fl = (-stut->fl);
	}
	convertf(stut);
	if (stut->width && stut->width > stut->accuracy)
	{
		i = (stut->grid && (!stut->dot || (stut->dot && !stut->accuracy))) ? \
	stut->width - stut->len - i - 1 : stut->width - stut->len - i;
		if (i > 0)
			ft_putnchar(' ', i, stut);
	}
	return (0);
}
