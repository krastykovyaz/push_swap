/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:35:52 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/23 19:05:44 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	ft_putstr(const char *str, t_pr *stut)
{
	if (str)
		write(1, str, ft_strlen(str));
	stut->nb += ft_strlen(str);
}

void	ft_putstring(char *line)
{
	if (line)
		write(1, line, ft_strlen(line));
}
