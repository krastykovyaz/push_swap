/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:09:04 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:39:37 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		precision(va_list ap, const char *format, t_pr *stut)
{
	if (format[stut->i] == '.')
	{
		stut->i += 1;
		stut->dot = 1;
		if (format[stut->i] == '*')
		{
			stut->accuracy = va_arg(ap, int);
			stut->i += 1;
		}
		else
		{
			stut->accuracy = ft_atoi(&format[stut->i]);
			while (if_digit(format[stut->i]))
				stut->i += 1;
		}
	}
	size(ap, format, stut);
	return (0);
}
