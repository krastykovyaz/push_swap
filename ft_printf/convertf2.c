/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertf2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 21:18:26 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 20:41:09 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		printafterdot(__int128_t f1, int i, int k, t_pr *stut)
{
	char *s;

	if (stut->dot == 0 || (stut->dot != 0 && stut->accuracy != 0))
	{
		ft_putchar('.', stut);
		s = ft_itoa2(f1);
		k = ft_strlen(s);
		free(s);
		if ((i - k) > 0)
			ft_putnchar('0', i - k, stut);
		ft_putnbr(f1, stut);
	}
	else if (stut->grid)
		ft_putchar('.', stut);
}

__int128_t	checknext(int i, int k, __int128_t f1, t_pr *stut)
{
	__int128_t f2;

	f1 = stut->fl * afterdot(10, i);
	f2 = stut->fl * (afterdot(10, i + 1));
	if (f2 - f1 * 10 > 4)
	{
		if (f1 == 0)
			f1++;
		else if (i == 19 && k != 18)
			;
		else
			f1++;
	}
	return (f1);
}

void		convertf2(t_pr *stut)
{
	long long int	nb;
	__int128_t		f1;
	int				i;
	int				k;

	k = 0;
	f1 = 0;
	i = (!stut->accuracy) ? 6 : stut->accuracy;
	nb = stut->fl;
	if (stut->fl < 0 && nb == 0)
		ft_putchar('-', stut);
	stut->fl = stut->fl - nb;
	if (stut->fl < 0)
		stut->fl = -(stut->fl);
	f1 = checknext(i, k, f1, stut);
	if ((ft_round(f1) != 9 && (int)(stut->fl * 10) == 9) || \
	((stut->dot && !stut->accuracy && ft_round(f1) > 4)))
	{
		f1 = 0;
		nb = (stut->fl_save > 0) ? nb + 1 : nb - 1;
	}
	ft_putnbr(nb, stut);
	printafterdot(f1, i, k, stut);
}
