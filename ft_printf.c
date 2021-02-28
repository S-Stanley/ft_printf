#include "./ft_printf.h"

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
