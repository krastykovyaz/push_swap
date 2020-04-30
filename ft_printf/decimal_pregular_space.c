/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_pregular_space.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:23:59 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/23 18:38:06 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		decimal_pregular_space(t_pr *stut)
{
	int	i;

	i = 0;
	if (stut->width > stut->len)
	{
		if (stut->width > stut->accuracy)
		{
			if (stut->accuracy > stut->len)
				i = stut->width - stut->accuracy;
			else
				i = stut->width - stut->len;
			if (stut->a < 0 && stut->accuracy >= stut->len)
				i--;
			ft_putnchar(' ', i, stut);
		}
	}
	return (i);
}
