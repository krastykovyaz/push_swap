/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 18:03:22 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 18:42:50 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	raise_memory_error(void)
{
	write(1, "\nft_printf: ", 12);
	write(1, "Memory alloc error\n", 19);
	exit(1);
}

void	raise_error(char *message)
{
	write(1, "\nft_printf: ", 12);
	ft_putstring(message);
	write(1, "\n", 1);
	exit(1);
}
