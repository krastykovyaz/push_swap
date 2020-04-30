/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:30:17 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/23 18:38:46 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_float(long long nb, __int128_t n, long long i, t_pr *stut)
{
	char	*s;

	ft_putnbr(nb, stut);
	if (!stut->dot || (stut->dot && stut->accuracy))
	{
		ft_putchar('.', stut);
		s = ft_itoa2(n);
		nb = ft_strlen(s);
		if ((i - nb) > 0)
			ft_putnchar('0', i - nb, stut);
		ft_putnbr(n, stut);
		free(s);
	}
	else if (stut->grid)
		ft_putchar('.', stut);
}
