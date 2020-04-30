/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_decimal_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:16:26 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/25 21:16:29 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	type_decimal_priority(const char *format, t_pr *stut)
{
	char	*str;

	str = ft_itoa(stut->a);
	stut->len = ft_strlen(str);
	free(str);
	if (stut->zero || stut->plus || stut->minus || stut->space)
	{
		if (stut->minus)
			type_decimal_minus(stut);
		else if (stut->plus)
			type_decimal_plus(format, stut);
		else if (stut->space)
			type_decimal_space(format, stut);
		else if (stut->zero)
			type_decimal_zero(stut);
	}
	else
		type_decimal_regular(stut);
}

void	if_1(va_list ap, const char *format, t_pr *stut)
{
	if (format[stut->i] == 'u')
		stut->a = va_arg(ap, unsigned long int);
	else
		stut->a = va_arg(ap, long int);
}

void	if_2(va_list ap, const char *format, t_pr *stut)
{
	if (format[stut->i] == 'u')
		stut->a = (unsigned char)va_arg(ap, int);
	else
		stut->a = (char)va_arg(ap, int);
}

void	if_3(va_list ap, const char *format, t_pr *stut)
{
	if (format[stut->i] == 'u')
		stut->a = (unsigned short)(va_arg(ap, unsigned int));
	else
		stut->a = (short)va_arg(ap, int);
}

int		type_decimal_size(va_list ap, const char *format, t_pr *stut)
{
	if (stut->size == 11)
		stut->a = va_arg(ap, long long int);
	else if (stut->size == 1)
		if_1(ap, format, stut);
	else if (stut->size == 22)
		if_2(ap, format, stut);
	else if (stut->size == 2)
		if_3(ap, format, stut);
	else
	{
		if (format[stut->i] == 'u')
			stut->a = va_arg(ap, unsigned int);
		else
			stut->a = va_arg(ap, int);
	}
	type_decimal_priority(format, stut);
	return (0);
}
