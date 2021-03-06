#include "ft_printf.h"

t_printer	ft_printer(char *str, t_res res, va_list data, t_flag flag)
{
	char 		*s;
	t_gvalue	gvalue;
	t_printer	printer;

	if (str[res.i] == '.' && flag.precis == 0)
		res.i++;
	gvalue = get_value(str[res.i], data, flag);
	s = gvalue.str;
	flag = gvalue.flag;
	if (ft_atoi(s) == 0 && flag.precis == 0 && flag.width == 0)
	{
		if (str[res.i - 1] == '.' || str[res.i - 2] == '.')
		{
			res.i++;
			printer.flag = flag;
			printer.res = res;
			return (printer);
		}
	}
	flag.letter = str[res.i];
	if (flag.letter == 'p' && flag.precis != 0)
		flag.precis = flag.precis + 2;
	if (flag.isprecision && flag.letter != 'c')
	{
		if (str[res.i] == 's' || str[res.i] == 'c' || str[res.i] == '%')
			s = ft_strndup(s, flag.precis);
		else if (flag.letter == 'p' && flag.precis == 0)
			s = ft_strdup("0x");
		else
		{
			if (flag.letter != '%')
				flag.sep = '0';
			s = ft_add_left_n(s, flag.precis, flag.sep, flag.letter);
			if (ft_isnum(flag.letter) && flag.precis < 0)
				flag.sep = '0';
			else
				flag.sep = ' ';
		}
	}
	if (flag.width)
	{
		if (ft_atoi(s) == 0 && flag.width == 0)
			s = ft_strdup("");
		if (flag.right)
			s = ft_add_right(s, flag.width, flag.sep);
		else
			s = ft_add_left(s, flag.width, flag.sep);
	}
	if (flag.letter == 'p' && ft_find(s, "0x"))
		s = put_it_first(s, "0x");
	res.str = ft_join(res.str, s);
	res.i++;
	printer.res = res;
	printer.flag = flag;
	return (printer);
}
