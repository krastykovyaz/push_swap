/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 21:21:45 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:38:37 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		float_zero(t_pr *stut)
{
	int	i;

	i = 0;
	if (stut->plus && stut->fl >= 0)
	{
		ft_putchar('+', stut);
		i++;
	}
	else if (stut->space && stut->fl >= 0)
	{
		ft_putchar(' ', stut);
		i++;
	}
	else if (stut->fl < 0)
		ft_putchar('-', stut);
	if (stut->width && stut->width > stut->accuracy)
		if (stut->width > stut->len + i)
			ft_putnchar('0', stut->width - (stut->len + i), stut);
	convertf(stut);
	return (0);
}
