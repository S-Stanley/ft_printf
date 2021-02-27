#include "./ft_printf.h"

t_res		ft_proxy(char *str, t_res res)
{
	(void)str;
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
			res = ft_proxy((char *)str, res);
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
