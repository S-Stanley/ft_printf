#include "ft_printf.h"

t_flag          init_flags()
{
        t_flag flag;

        flag.width = 0;
        flag.right = 0;
        flag.sep = ' ';
	flag.precis = 0;
        return (flag);
}

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
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(data, int)));
	if (c == '%')
		return (ft_strdup("%"));
	return (ft_strdup(""));
}

int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int	i;
	char	*s;

	i = 0;
	s = malloc(sizeof(char) * (ft_intlen(nb) + 1));
	if (!s)
		return (NULL);
	while (nb >= 1)
	{
		s[i] = (nb % 10) + 48;
		i++;
		nb = nb / 10;
	}
	s[i] = '\0';
	return (reverse_table(s));
}

char	*reverse_table(char *str)
{
	char	*s;
	int	i;
	int	x;

	i = 0;
	x = ft_strlen(str) - 1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	while (x >= 0)
	{
		s[i] = str[x];
		i++;
		x--;
	}
	s[i] = '\0';
	return (s);
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
