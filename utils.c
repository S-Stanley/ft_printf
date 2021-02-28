#include "ft_printf.h"

char		*ft_strdup(char *str)
{
	char	*s;
	int	i;	

	i = -1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

char            *ft_joinchar(char *str, char c)
{
        int     i;
        char    *s;

        i = -1;
        s = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!s)
		return (NULL);
        while (str[++i])
                s[i] = str[i];
        s[i] = c;
        s[++i] = '\0';
        return (s);
}

char	*get_value(char c, va_list data)
{
	if (c == 's')
		return (va_arg(data, char *));
	return (ft_strdup(""));
}

char	*ft_join(char *s1, char *s2)
{
	int	i;
	int	x;
	char	*s;

	i = 0;
	x = 0;
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		s[i] = s2[x];
		x++;
		i++;
	}
	s[i] = '\0';
	return (s);
}
