#include "./ft_printf.h"

t_proxy		ft_proxy(char *str, t_res res, va_list data, t_flag flag)
{
	t_proxy		render;
	t_printer	printer;

	res.i++;
	render.flag = flag;
	render.res = res;
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
	if (ft_is_prevision(&str[res.i]))
	{
		flag.isprecision = 1;
		flag = ft_get_precision(str, res, data, flag);
		res.i = flag.i;
	}
	printer = ft_printer(str, res, data, flag);
	render.res = printer.res;
	render.flag = printer.flag;
	return (render);
}

int		ft_printf(const char *str, ...)
{
	va_list	data;
	t_res	res;
	t_flag	flag;
	t_proxy	render;

	res.i = 0;
	res.str = ft_strdup("");
	va_start(data, str);
	while (str[res.i])
	{
		if (str[res.i] == '%')
		{
			flag = init_flags();
			render = ft_proxy((char *)str, res, data, flag);
			res = render.res;
		}
		else
		{
			res.str = ft_joinchar(res.str, str[res.i], flag, 0).str;
			res.i++;
		}
	}
	va_end(data);
	return (ft_putstr(res.str, render.flag));
}
