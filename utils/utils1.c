#include "../ft_printf.h"

int		ft_isnum(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'u')
		return (1);
	return (0);
}

int		check_ingredients(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_count_hexa(int nb)
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

char	*str_that_address(unsigned long long n)
{
	long int			container;
	char				tmp;
	char				*str;
	int					i;

	i = -1;
	if (n == 0 || n == 1)
		return (address_exception(n));
	container = 16;
	str = get_malloc(ft_intlen(n) + 3);
	while (n / container >= 16)
		container = container * 16;
	while (container > 0)
	{
		tmp = n / container + '0';
		if (tmp > '9')
			str[++i] = tmp + 39;
		else
			str[++i] = tmp;
		n = n % container;
		container = container / 16;
	}
	str[++i] = '\0';
	return (ft_join("0x", str));
}