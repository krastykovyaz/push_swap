/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 19:20:45 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/23 19:22:40 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	ft_equal(char *one, char *two)
{
	int i;

	if (ft_strlen(one) != ft_strlen(two))
		return (0);
	i = 0;
	while (one[i] != '\0')
	{
		if (one[i] != two[i])
			return (0);
		i++;
	}
	return (1);
}
