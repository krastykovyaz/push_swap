#include "./includes/checker.h"

static size_t count_words(const char *s, char c)
{
    size_t flag;
    size_t i;

    i = 0;
    flag = 0;
    while(*s)
    {
        if (!flag && *s == c)
            flag = 1;
        if (*s != c && flag)
        {
            flag = 0;
            i++;
        }
        s++;
    }
    return (i);

}

char *ft_strsub(const char *s, unsigned int a, size_t b)
{
    char *tab;
    unsigned int i;

    if(!s || !(tab = (char *)malloc(sizeof(char *) * (b + 1))))
        return (NULL);
    i = 0;
    while(b > 0)
    {
        if(s[a + i] == '\0')
            return (0);
        tab[i] = s[a + 1];
        i++;
        b--;
    }
    tab[i] = '\0';
    return (tab);
}

static char    **ft_free(char **s, size_t i)
{
    while (i > 0)
    {
        free(s[i]);
        i--;
    }
    free(s[i]);
    free(s);
    s = NULL;
    return (s);
}

char **ft_strsplit(const char *s, char c)
{
    char **tab;
    size_t count;
    size_t i;
    size_t j;

    count = count_words((char *)s, c);
    if (!s || !(tab = (char **)malloc(sizeof(char*) * (count + 1))))
        return (NULL);
    i = 0;
    while (i < count)
    {
        while (s && *s == c)
            s++;
        j = 0;
        while (s && *s != c)
        {
            j++;
            s++;
        }
        if (!(tab[i] = ft_strsub(s, 0, j)))
            return (ft_free(tab, i));
        while (s && *s != c)
            s++;
        i++;
    }
    tab[i] = NULL;
    return (tab);
}