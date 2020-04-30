/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:35:27 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/23 18:39:15 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_putnstr(const char *s, int k, t_pr *stut)
{
	int i;

	i = 0;
	while (k)
	{
		ft_putchar(s[i], stut);
		k--;
		i++;
	}
}
