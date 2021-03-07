#include "../ft_printf.h"

t_res	init_res(void)
{
	t_res	res;

	res.i = 0;
	res.str = ft_strdup("");
	return (res);
}

char	*ft_clean(char *str, char *to_del)
{
	int		i;
	int		x;
	int		keep;
	char	*s;
	int		index;

	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	index = -1;
	while (str[i])
	{
		x = 0;
		keep = i;
		while (to_del[x] == str[i])
		{
			i++;
			x++;
		}
		if (x != ft_strlen(to_del))
			i = keep;
		s[++index] = str[i];
		i++;
	}
	s[++index] = '\0';
	return (s);
}

char	*put_it_first(char *str, char *to_move)
{
	char	*s;
	char	*s2;
	int		i;
	int		x;
	int		y;

	s2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	s = ft_clean(str, to_move);
	i = 0;
	x = 0;
	y = 0;
	while (s[i] == ' ')
	{
		s2[x] = s[i];
		x++;
		i++;
	}
	while (to_move[y])
	{
		s2[x] = to_move[y];
		x++;
		y++;
	}
	while (s[i])
	{
		s2[x] = s[i];
		x++;
		i++;
	}
	s2[x] = '\0';
	return (s2);
}

char	*address_exception(unsigned long long n)
{
	if (n == 0)
		return (ft_strdup("0x0"));
	else
		return (ft_strdup("0x1"));
}

char	*give_s_of_itoa_hexa(unsigned int nb, int add)
{
	char	*s;
	int		c;
	int		i;

	s = malloc(sizeof(char) * (ft_count_hexa(nb) + 2));
	i = 0;
	while (nb >= 1)
	{
		c = (nb % 16) + 48;
		if (c >= 58)
			c = c + 7 + add;
		s[i] = c;
		i++;
		nb = nb / 16;
	}
	s[i] = '\0';
	s = reverse_table(s);
	return (s);
}