#include "./ft_printf.h"

t_res		ft_proxy(char *str, t_res res, va_list data)
{
	char *s;
	
	res.i++;
	s = get_value(str[res.i], data);
	if (ft_is_flag(&str[res.i]))
	{
		printf("FLAG ");
	}
	if (ft_is_with(&str[res.i]))
		printf("WITH ");
	if (ft_is_prevision(&str[res.i]))
		printf("PRECISION ");
	if (ft_isletter(&str[res.i]))
	{
		res.str = ft_join(res.str, s);
		res.i++;
	}
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
