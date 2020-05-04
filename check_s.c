#include "./includes/checker.h"

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