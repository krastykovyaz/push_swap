/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 22:58:14 by lnoisome          #+#    #+#             */
/*   Updated: 2020/06/05 22:58:27 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/header.h"

int	main(int ac, char **av)
{
	t_stack *a;

	a = init_stack_with_char_mass(ac, av);
	switcher(a);
	return (0);
}
