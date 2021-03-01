#include "ft_printf.h"

int	ft_count_hexa(int nb)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*str_that_address(int nb)
{
	long int			container;
	char				tmp;
	unsigned long int	n;
	char				*str;
	int					i;

	i = -1;
	n = (unsigned long int)nb;
	container = 16;
	str = malloc(sizeof(char) * (ft_intlen(n) + 1));
	while (n / container >= 16)
		container = container * 16;
	str[++i] = '0';
	str[++i] = 'x';
	while (container > 0)
	{
		tmp = n / container + '0';
		if (tmp > '9')
		{
			tmp = tmp + 39;
			str[++i] = tmp;
		}
		else
			str[++i] = tmp;
		n = n % container;
		container = container / 16;
	}
	str[++i] = 0;
	return (str);
}

char	*ft_putinsigned_int(int nbr)
{
	unsigned int	n;
	char			*s;
	int				i;

	n = (unsigned int)nbr;
	s = malloc(sizeof(char) * (ft_intlen(n) + 1));
	i = -1;
	if (n == 0 || n == 1)
		return (ft_strndup(ft_itoa(n), 2));
	while (n >= 1)
	{
		s[++i] = (n % 10) + '0';
		n = n / 10;
	}
	s[++i] = '\0';
	return (reverse_table(s));
}

char    *ft_itoa_hexa_min(int nb)
{
        int     i;
        char    *s;
        int     minus;
	int	c;

	if (nb == 0)
                return (ft_strdup("0"));
        i = 0;
        minus = 0;
        s = malloc(sizeof(char) * (ft_count_hexa(nb) + 2));
        if (!s)
                return (NULL);
        if (nb < 0)
        {
                nb = -nb;
                minus = 1;
        }
        while (nb >= 1)
        {
		c = (nb % 16) + 48;
		if (c >= 58)
			c = c + 7 + 32;
                s[i] = c;
                i++;
                nb = nb / 16;
        }
        s[i] = '\0';
        s = reverse_table(s);
        if (minus)
                s = ft_join("-", s);
        return (s);
}

char    *ft_itoa_hexa_maj(int nb)
{
        int     i;
        char    *s;
        int     minus;
        int     c;

	if (nb == 0)
                return (ft_strdup("0"));
        i = 0;
        minus = 0;
        s = malloc(sizeof(char) * (ft_count_hexa(nb) + 2));
        if (!s)
                return (NULL);
        if (nb < 0)
        {
                nb = -nb;
                minus = 1;
        }
        while (nb >= 1)
        {
                c = (nb % 16) + 48;
                if (c >= 58)
                        c = c + 7;
                s[i] = c;
                i++;
                nb = nb / 16;
        }
        s[i] = '\0';
        s = reverse_table(s);
        if (minus)
                s = ft_join("-", s);
        return (s);
}

int		ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	minus;

	minus = 1;
	nb = 0;
	i = 0;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i])
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * minus);
}

char		*ft_strndup(char *str, int max)
{
	int	i;
	char	*s;

	i = -1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	while (str[++i] && i < max)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

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
	if (c == 'x')
		return (ft_itoa_hexa_min(va_arg(data, int)));
	if (c == 'X')
		return (ft_itoa_hexa_maj(va_arg(data, int)));
	if (c == 'p')
		return (str_that_address(va_arg(data, int)));
	if (c == 'u')
		return (str_that_address(va_arg(data, int)));
	if (c == 'c')
		return (ft_joinchar("", (char)va_arg(data, int)));
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
	int	minus;

	if (nb == 0)
		return (ft_strdup("0"));
	i = 0;
	minus = 0;
	s = malloc(sizeof(char) * (ft_intlen(nb) + 2));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		minus = 1;
	}
	while (nb >= 1)
	{
		s[i] = (nb % 10) + 48;
		i++;
		nb = nb / 10;
	}
	s[i] = '\0';
	s = reverse_table(s);
	if (minus)
		s = ft_join("-", s);
	return (s);
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
