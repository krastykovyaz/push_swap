/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:33:02 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/23 20:08:46 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	ft_printf(const char *format, ...)
{
	t_pr	stut;
	va_list	ap;

	stut.i = 0;
	stut.nb = 0;
	va_start(ap, format);
	while (format[stut.i] != '\0')
	{
		free_list(&stut);
		while (format[stut.i] != '%' && format[stut.i] != '\0')
		{
			if (format[stut.i] == '{')
				parse_colors_flags(format, &stut);
			if (format[stut.i] == '%')
				break ;
			ft_putchar(format[stut.i], &stut);
			stut.i++;
		}
		if (format[stut.i] == '%')
			percent(ap, format, &stut);
	}
	va_end(ap);
	return (stut.nb);
}
