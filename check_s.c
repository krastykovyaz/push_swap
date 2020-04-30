#include "./includes/checker.h"

// char *ft_itoa(int n)
// {
// 	char *result;
// 	int sign;
// 	int power;
// 	int i;

// 	i = 1;
// 	sign = 1;
// 	if (n < 0)
// 		sign = -1;
// 	power = 1;
// 	while (n / 10 / power != 0 && ++i)
// 		power = power * 10;
// 	if (!(result = malloc(sizeof(char) * (unsigned long)(i + sign + 1))))
// 		return (NULL);
// 	i = 0;
// 	if (sign == -1)
//     {
// 		result[i++] = '-';
//         sign = -1;
//     }
// 	while (power != 0)
// 	{
// 		result[i] = (char)((int)n * sign / power + '0');
// 		n = n % power;
// 		power =power / 10;
//         i++;
// 	}
// 	result[i++] = '\0';
// 	return (result);
// }

int ft_strcmp(const char *s1, const char *s2)
{
	int i;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// __int128_t ft_atoi(const char *s)
// {
// 	__int128_t nb;
// 	int         i;
// 	int         sign;

// 	nb = 0;
// 	i = 0;
// 	sign = 1;
// 	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' ||\
// 	s[i] == '\f' || s[i] == '\n')
// 		i++;
// 	sign = (s[i] == '-') ? -1 : 1;
// 	if (s[i] == '+' || s[i] == '-')
// 		i++;
// 	while (s[i] == '0')
// 		i++;
// 	while (s[i] >= '0' && s[i] < '9')
// 	{
// 		nb = nb * 10 + (s[i] - '0');
// 		i++;
// 	}
// 	return (nb *sign);
// }

int add_ch(char *s)
{
	char *a;
	char *b;

	a = ft_itoaS(ft_atoiS(s));
	b = ft_itoaS(ft_atoiS(&s[1]));
	if (((s[0] == '+') && (ft_strcmp(&s[1], b))) ||\
	((s[0] != '+') && ft_strcmp(s, a)))
	{
		free(a);
		free(b);
		return (1);
	}
	else
	{
		free(a);
		free(b);
		return (0);
	}
}

int check_s(char **s)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] >= 48 && s[i][j] <= 57)
				j++;
			else if ((s[i][j] == '-' || s[i][j] == '+') &&\
	s[i][j + 1] != '\0' && s[i][j + 1] >= 48 && s[i][j] <= 57)
				j++;
			else
				return (1);
		}
		if (add_ch(s[i]))
			return (1);
		j = 0;
		i++;
	}
	return (0);
}