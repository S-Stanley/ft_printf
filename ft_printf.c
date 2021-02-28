#include "./ft_printf.h"

t_res		ft_proxy(char *str, t_res res, va_list data)
{
	t_flag	flag;
	
	res.i++;
	flag = init_flags();
	if (ft_is_flag(&str[res.i]))
	{
		flag = ft_get_flag(flag, res, str);
		res.i = flag.i;
	}
	if (ft_is_with(&str[res.i]))
	{
		flag = get_width(str, res, data, flag);
		res.i = flag.i;
	}
	if (str[res.i] == '*')
	if (ft_is_prevision(&str[res.i]))
		printf("PRECISION ");
	return (ft_printer(str, res, data, flag));
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
