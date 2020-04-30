/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 20:28:54 by ccharmai          #+#    #+#             */
/*   Updated: 2020/04/23 18:38:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	free_list(t_pr *stut)
{
	stut->zero = 0;
	stut->plus = 0;
	stut->minus = 0;
	stut->space = 0;
	stut->grid = 0;
	stut->width = 0;
	stut->accuracy = 0;
	stut->size = 0;
	stut->a = 0;
	stut->len = 0;
	stut->dot = 0;
}
