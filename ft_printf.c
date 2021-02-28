#include "./ft_printf.h"

t_res		ft_proxy(char *str, t_res res, va_list data)
{
	char 	*s;
	t_flag	flag;
	
	res.i++;
	flag.width = 0;
	flag.right = 0;
	flag.sep = ' ';
	if (ft_is_flag(&str[res.i]))
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
		}
	}
	if (ft_is_with(&str[res.i]))
	{
		flag = get_width(str, res, data, flag);
		res.i = flag.i;
	}
	if (str[res.i] == '*')
	if (ft_is_prevision(&str[res.i]))
		printf("PRECISION ");
	s = get_value(str[res.i], data);

	if (flag.width)
	{
		if (flag.right)
			s = ft_add_right(s, flag.width, flag.sep);
		else
			s = ft_add_left(s, flag.width, flag.sep); 
	}
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
