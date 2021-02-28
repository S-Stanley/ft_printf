#include "ft_printf.h"

t_res		ft_printer(char *str, t_res res, va_list data, t_flag flag)
{
	char *s;

        s = get_value(str[res.i], data);
        if (flag.precis)
        {
                if (str[res.i] == 's')
                        s = ft_strndup(s, flag.precis);
                else
                        s = ft_add_left(s, flag.precis, flag.sep);
        }
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

