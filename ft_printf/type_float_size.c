/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:29:36 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:40:17 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		len_a_dot(t_pr *stut)
{
	int		nb;
	char	*s;
	int		i;

	nb = stut->fl_save;
	s = ft_itoa(nb);
	i = ft_strlen(s) + 1;
	free(s);
	if (stut->dot == 0)
		i += 6;
	else if (stut->dot && !stut->accuracy)
		i--;
	else
		i += stut->accuracy;
	return (i);
}

int		type_float_size(va_list ap, t_pr *stut)
{
	if (stut->size == 1)
		stut->fl = va_arg(ap, double);
	else if (stut->size == 3)
		stut->fl = va_arg(ap, long double);
	else
		stut->fl = (double)va_arg(ap, double);
	stut->fl_save = stut->fl;
	stut->len = len_a_dot(stut);
	type_float_priority(stut);
	return (0);
}
