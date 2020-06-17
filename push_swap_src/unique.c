/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 23:04:11 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 23:04:13 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_unique_int_mass(int len, int *mass)
{
	int	i;
	int	z;

	i = 0;
	if (len == 1)
		return (1);
	while (i < len - 1)
	{
		z = i + 1;
		while (z < len)
		{
			if (mass[i] == mass[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}
