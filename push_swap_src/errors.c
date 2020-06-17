/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:02:05 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:02:07 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

void	raise_not_integer_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	raise_not_unique_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	raise_memory_error(void)
{
	write(2, "Memory error detected\n", 22);
	exit(1);
}
