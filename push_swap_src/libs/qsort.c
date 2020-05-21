/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharmai <5429549@mail.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:28:17 by ccharmai          #+#    #+#             */
/*   Updated: 2020/05/16 22:16:58 by ccharmai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

static void	init_i_j(int *i, int *j, int len)
{
	*i = 0;
	*j = len - 1;
}

static void	swap_mass(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		ft_qsort(int len, int *mass)
{
	int i;
	int j;
	int mid;

	init_i_j(&i, &j, len);
	mid = mass[len / 2];
	while (i <= j)
	{
		while (mass[i] < mid)
			i++;
		while (mass[j] > mid)
			j--;
		if (i <= j)
		{
			swap_mass(&mass[i], &mass[j]);
			i++;
			j--;
		}
	}
	if (j > 0)
		ft_qsort(j + 1, mass);
	if (i < len)
		ft_qsort(len - i, &mass[i]);
}
