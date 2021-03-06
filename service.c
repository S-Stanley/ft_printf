#include "ft_printf.h"

t_flag		ft_get_precision(char *str, t_res res, va_list data, t_flag flag)
{
	res.i++;
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
	s2 = malloc(sizeof(char) * (ft_strlen(s) + size_min + 1));
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

char		*ft_add_left(char *s, int size_min, char sep)
{
	int		size;
	char	*s2;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (size_min > 0)
	{
		size = size_min - ft_strlen(s);
		s2 = malloc(sizeof(char) * (ft_strlen(s) + size_min + 1));
		if (ft_atoi(s) < 0 && sep == '0' && ft_strcmp(s, "%") != 0)
		{
			s2[i] = '-';
			i++;
			if (ft_atoi(s) == -2147483648)
				s = "2147483648";
			else
				s = ft_itoa(ft_atoi(s) * -1);
		}
		while (size-- > 0)
		{
			s2[i] = sep;
			i++;
		}
		while (s[x])
		{
			s2[i] = s[x];
			i++;
			x++;
		}
		s2[i] = '\0';
	}
	else
	{
		if (size_min < 0)
			size_min = -size_min;
		size = size_min - ft_strlen(s);
		s2 = malloc(sizeof(char) * (ft_strlen(s) + size_min + 1));
		if (ft_atoi(s) < 0 && sep == '0')
		{
			s2[i] = '-';
			i++;
			s = ft_itoa(ft_atoi(s) * -1);
		}
		while (s[x])
		{
			s2[i] = s[x];
			i++;
			x++;
		}
		while (size-- > 0)
		{
			s2[i] = sep;
			i++;
		}
		s2[i] = '\0';
	}
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
		s2 = malloc(sizeof(char) * (ft_strlen(s) + size + 1));
		while (s[x] && x < size)
		{
			s2[i] = s[x];
			i++;
			x++;
		}
	}
	else
	{
		if (size < 0)
			return (s);
		s2 = malloc(sizeof(char) * (ft_strlen(s) + size + 1));
		if (ft_atoi(s) < 0 && sep == '0' && letter != 'u')
		{
			s2[i] = '-';
			i++;
			if (ft_strcmp(s, "-2147483648") == 0)
				s = ft_strdup("2147483648");
			else
				s = ft_itoa(ft_atoi(s) * -1);
			size++;
		}
		while (size-- > 0)
		{
			s2[i] = sep;
			i++;
		}
		while (s[x])
		{
			s2[i] = s[x];
			i++;
			x++;
		}
	}
	s2[i] = '\0';
	return (s2);
}

t_flag		get_width(char *str, t_res res, va_list data, t_flag flag)
{
	int		nb;

	while (str[res.i] == '-')
	{
		res.i++;
		flag.neg = 1;
	}
	if (str[res.i] == '*')
	{
		nb = va_arg(data, int);
		if (nb < 0)
		{
			nb = -nb;
			flag.right = 1;
			flag.sep = ' ';
		}
		flag.width = nb;
		res.i++;
	}
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
