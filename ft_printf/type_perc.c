/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_perc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 21:54:21 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 10:33:48 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		pr(char c, t_pr *stut)
{
	if (c)
	{
		ft_putnchar('0', stut->width - 1, stut);
		ft_putchar(c, stut);
	}
	else
		ft_putnchar('0', stut->width, stut);
}

int			type_perc(t_pr *stut)
{
	char	c;

	c = '%';
	if ((stut->minus || !stut->zero) && stut->width)
	{
		if (c)
		{
			if (stut->minus)
				ft_putchar(c, stut);
			ft_putnchar(' ', stut->width - 1, stut);
			if (c && !stut->minus)
				ft_putchar(c, stut);
		}
		else if (!c)
			ft_putnchar(' ', stut->width, stut);
	}
	else if (stut->zero)
		pr(c, stut);
	else
		ft_putchar(c, stut);
	return (0);
}
