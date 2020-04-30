/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnoisome <lnoisome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 21:54:28 by lnoisome          #+#    #+#             */
/*   Updated: 2020/04/24 10:33:47 by lnoisome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	int		sum;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	sum = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s3 = (char *)malloc(sizeof(char *) * sum);
	if (!s3)
		return (NULL);
	while (sum-- > 0)
		((unsigned char *)s3)[sum] = 0;
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}

int			type_address(const char *format, void *p, t_pr *stut)
{
	char	*s;
	char	*b;
	int		i;

	stut->a = (unsigned long)p;
	s = convert_hex(format, stut, 16);
	b = s;
	s = ft_strjoin("0x", s);
	free(b);
	i = (int)ft_strlen(s);
	if (stut->minus)
		ft_putstr(s, stut);
	if (stut->width && (stut->width > i))
		ft_putnchar(' ', stut->width - i, stut);
	if (!stut->minus)
		ft_putstr(s, stut);
	free(s);
	return (0);
}
