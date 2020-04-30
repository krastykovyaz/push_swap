/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:09:42 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/25 21:32:09 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		search_type(va_list ap, const char *format, t_pr *stut)
{
	if (format[stut->i] == 'd' || format[stut->i] == 'i' || \
	format[stut->i] == 'u')
		type_decimal_size(ap, format, stut);
	else if (format[stut->i] == 'o')
		type_octal_size(ap, stut);
	else if (format[stut->i] == 'x' || format[stut->i] == 'X')
		type_hex_size(ap, format, stut);
	else if (format[stut->i] == 'f')
		type_float_size(ap, stut);
	else if (format[stut->i] == 's' || format[stut->i] == 'c')
		type_str(ap, format, stut);
	else if (format[stut->i] == 'p')
		type_address(format, va_arg(ap, void*), stut);
	else if (format[stut->i] == '%')
		type_perc(stut);
	else
		ft_putchar(format[stut->i], stut);
	stut->i += 1;
	return (0);
}
