/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 09:34:03 by aleksandrko       #+#    #+#             */
/*   Updated: 2020/04/23 18:40:31 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		type_priority_hex(const char *format, t_pr *stut)
{
	char	*s;

	s = convert_hex(format, stut, 16);
	stut->ptr = s;
	free(s);
	stut->len = ft_strlen(stut->ptr);
	if (stut->grid && stut->a)
		stut->width -= 2;
	if (stut->minus)
		type_hex_minus(format, stut);
	else
		type_hex_regular(format, stut);
	return (0);
}

int		type_hex_size(va_list ap, const char *format, t_pr *stut)
{
	if (stut->size == 11)
		stut->a = va_arg(ap, unsigned long long int);
	else if (stut->size == 22)
		stut->a = (unsigned char)va_arg(ap, long);
	else if (stut->size == 1)
		stut->a = va_arg(ap, long);
	else if (stut->size == 2)
		stut->a = (unsigned short)va_arg(ap, int);
	else
		stut->a = va_arg(ap, unsigned int);
	type_priority_hex(format, stut);
	return (0);
}
