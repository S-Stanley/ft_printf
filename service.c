#include "ft_printf.h"

t_flag		ft_get_precision(char *str, t_res res, va_list data, t_flag flag)
{
	res.i++;
	flag.isprecision = 1;
	if (str[res.i] == '*')
	{
		flag.precis = va_arg(data, int);
		res.i++;
	}
	else
	{
		while (str[res.i] >= '0' && str[res.i] <= '9')
		{
			flag.precis = (flag.precis * 10) + (str[res.i] - 48);
			res.i++;
		}
	}
	flag.i = res.i;
	return (flag);
}

t_flag		ft_get_flag(t_flag flag, t_res res, char *str)
{
	if (str[res.i] == '0')
	{
		flag.sep = '0';
		res.i++;
		flag.flag = '0';
	}
	if (str[res.i] == '-')
	{
		flag.right = 1;
		res.i++;
		flag.neg = 1;
	}
	flag.i = res.i;
	return (flag);
}

char		*ft_add_right(char *s, int size_min, char sep)
{
	int		size;
	char	*s2;
	int		i;

	i = 0;
	size = size_min - ft_strlen(s);
	s2 = get_malloc(ft_strlen(s) + size_min + 1);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	while (size-- > 0)
		s2[i++] = sep;
	s2[i] = '\0';
	return (s2);
}

char		*add_left_pos(int size_min, char *s, char sep)
{
	int		size;
	int		i;
	int		x;
	char	*s2;

	i = 0;
	x = 0;
	size = size_min - ft_strlen(s);
	s2 = get_malloc(ft_strlen(s) + size_min + 1);
	if (ft_atoi(s) < 0 && sep == '0' && ft_strcmp(s, "%") != 0)
	{
		s2[i++] = '-';
		if (ft_atoi(s) == -2147483648)
			s = "2147483648";
		else
			s = ft_itoa(ft_atoi(s) * -1);
	}
	while (size-- > 0)
		s2[i++] = sep;
	while (s[x])
		s2[i++] = s[x++];
	s2[i] = '\0';
	return (s2);
}

char		*add_left_neg(int size_min, char *s, char sep)
{
	int		size;
	int		i;
	int		x;
	char	*s2;

	i = 0;
	x = 0;
	if (size_min < 0)
		size_min = -size_min;
	size = size_min - ft_strlen(s);
	s2 = get_malloc(ft_strlen(s) + size_min + 1);
	if (ft_atoi(s) < 0 && sep == '0')
	{
		s2[i++] = '-';
		s = ft_itoa(ft_atoi(s) * -1);
	}
	while (s[x])
		s2[i++] = s[x++];
	while (size-- > 0)
		s2[i++] = sep;
	s2[i] = '\0';
	return (s2);
}

char		*ft_add_left(char *s, int size_min, char sep)
{
	if (size_min > 0)
		return (add_left_pos(size_min, s, sep));
	else
		return (add_left_neg(size_min, s, sep));
}

char		*add_left_n_else(char *s, int size, char sep, char letter)
{
	char	*s2;
	int		x;
	int		i;

	x = 0;
	i = 0;
	if (size < 0)
		return (s);
	s2 = get_malloc(ft_strlen(s) + size + 1);
	if (ft_atoi(s) < 0 && sep == '0' && letter != 'u')
	{
		s2[i++] = '-';
		if (ft_strcmp(s, "-2147483648") == 0)
			s = ft_strdup("2147483648");
		else
			s = ft_itoa(ft_atoi(s) * -1);
		size++;
	}
	while (size-- > 0)
		s2[i++] = sep;
	while (s[x])
		s2[i++] = s[x++];
	s2[i] = '\0';
	return (s2);
}

char		*ft_add_left_n(char *s, int size_min, char sep, char letter)
{
	int		size;
	char	*s2;
	int		i;
	int		x;

	i = 0;
	x = 0;
	size = size_min - ft_strlen(s);
	if (size <= 0 && ft_strcmp(s, "0") == 0)
	{
		size = size_min;
		if (size < 0)
			return (s);
		s2 = get_malloc(ft_strlen(s) + size + 1);
		while (s[x] && x < size)
			s2[i++] = s[x++];
		s2[i] = '\0';
		return (s2);
	}
	else
		return (add_left_n_else(s, size, sep, letter));
}

t_flag		get_width_star(t_flag flag, t_res res, va_list data)
{
	int		nb;

	nb = va_arg(data, int);
	if (nb < 0)
	{
		nb = -nb;
		flag.right = 1;
		flag.sep = ' ';
	}
	flag.width = nb;
	res.i++;
	flag.i = res.i;
	return (flag);
}

t_flag		get_width(char *str, t_res res, va_list data, t_flag flag)
{
	int		nb;

	while (str[res.i] == '0' || str[res.i] == '-')
	{
		if (str[res.i] == '-')
			flag.neg = 1;
		res.i++;
	}
	if (str[res.i] == '*')
		return (get_width_star(flag, res, data));
	else
	{
		while (str[res.i] >= '0' && str[res.i] <= '9')
		{
			flag.width = (flag.width * 10) + (str[res.i] - 48);
			res.i++;
			flag.iswidth++;
		}
	}
	flag.i = res.i;
	return (flag);
}
