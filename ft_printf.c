#include "./ft_printf.h"

char		*ft_add_left(char *s, int size_min)
{
	int	size;
	char	*s2;
	int	i;
	int	x;

	i = 0;
	x = 0;
	size = size_min - ft_strlen(s);
	s2 = malloc(sizeof(char) * (ft_strlen(s) + size_min + 1));
	while (size-- > 0)
	{
		s2[i] = ' ';
		i++;
	}
	while (s[x])
	{
		s2[i] = s[x];
		i++;
		x++;
	}
	s2[i] = '\0';
	return (s2);
}

typedef struct s_width{
	int	value;
	int	i;
}	t_width;

t_width		get_width(char *str, t_res res, va_list data)
{
	t_width	width;

	width.value = 0;
	if (str[res.i] == '*')
	{
		width.value = va_arg(data, int);
		res.i++;
	}
	else
	{
		while (str[res.i] >= '1' && str[res.i] <= '9')
		{
			width.value = (width.value * 10) + (str[res.i] - 48);
			res.i++;
		}
	}
	width.i = res.i;
	return (width);
}

t_res		ft_proxy(char *str, t_res res, va_list data)
{
	char 	*s;
	t_width	width;
	
	res.i++;
	width.value = 0;
	if (ft_is_flag(&str[res.i]))
	{
		printf("FLAG ");
	}
	if (ft_is_with(&str[res.i]))
	{
		width = get_width(str, res, data);
		res.i = width.i;
	}
	if (str[res.i] == '*')
	if (ft_is_prevision(&str[res.i]))
		printf("PRECISION ");
	s = get_value(str[res.i], data);

	if (width.value)
		s = ft_add_left(s, width.value); 
	res.str = ft_join(res.str, s);
	res.i++;
	return (res);
}

int		ft_printf(const char *str, ...)
{
	va_list	data;
	t_res	res;

	res.i = 0;
	res.str = ft_strdup("");
	va_start(data, str);
	while (str[res.i])
	{
		if (str[res.i] == '%')
			res = ft_proxy((char *)str, res, data);
		else
		{
			res.str = ft_joinchar(res.str, str[res.i]);
			res.i++;
		}
	}
	va_end(data);
	ft_putstr(res.str);
	return (ft_strlen(res.str));
}
