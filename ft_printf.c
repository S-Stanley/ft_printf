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

t_res		ft_proxy(char *str, t_res res, va_list data)
{
	char 	*s;
	int	width;
	
	res.i++;
	width = 0;
	if (ft_is_flag(&str[res.i]))
	{
		printf("FLAG ");
	}
	if (ft_is_with(&str[res.i]))
	{
		if (str[res.i] == '*')
			printf("star");
		else
		{
			while (str[res.i] >= '1' && str[res.i] <= '9')
			{
				width = (width * 10) + (str[res.i] - 48);
				res.i++;
			}
		}
	}
	if (ft_is_prevision(&str[res.i]))
		printf("PRECISION ");
	if (ft_isletter(&str[res.i]))
		s = get_value(str[res.i], data);


	if (width)
		s = ft_add_left(s, width); 
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
