/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 21:23:01 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:38:31 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		float_plus(t_pr *stut)
{
	int	i;

	i = 0;
	if (stut->width && stut->width > stut->accuracy)
	{
		if (stut->fl > 0)
			i += 1;
		i = stut->width - stut->len - i;
		if (i > 0)
			ft_putnchar(' ', i, stut);
	}
	if (stut->fl >= 0)
		ft_putchar('+', stut);
	else
	{
		ft_putchar('-', stut);
		stut->fl = -(stut->fl);
	}
	convertf(stut);
	return (0);
}
