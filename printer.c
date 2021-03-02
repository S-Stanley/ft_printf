#include "ft_printf.h"

t_res		ft_printer(char *str, t_res res, va_list data, t_flag flag)
{
	char *s;

	if (str[res.i] == '.' && flag.precis == 0)
		res.i++;
    s = get_value(str[res.i], data);
	if (ft_atoi(s) == 0 && flag.precis == 0 && flag.width == 0)
	{
		if (str[res.i-1] == '.' || str[res.i-2] == '.')
		{
			res.i++;
			return (res);
		}
	}
	flag.letter = str[res.i];
	if (flag.isprecision)
	{
		if (str[res.i] == 's' || str[res.i] == 'c')
			s = ft_strndup(s, flag.precis);
		else
		{
			flag.sep = '0';
			s = ft_add_left_n(s, flag.precis, flag.sep, flag.letter);
			flag.sep = ' ';
		}
	}
	// else if (!flag.precis && check_ingredients(flag.letter, "dipxXu"))
	// {
	// 	if (flag.isprecision && flag.letter == 'p')
	// 		s = ft_strdup("0x");
	// 	else if (flag.isprecision && flag.letter != 'p')
	// 		s = ft_strdup("");
	// }
	if (flag.width)
	{
		if (ft_atoi(s) == 0 && flag.width == 0)
			s = ft_strdup("");
		if (flag.right)
			s = ft_add_right(s, flag.width, flag.sep);
		else
			s = ft_add_left(s, flag.width, flag.sep);
	}
	res.str = ft_join(res.str, s);
	res.i++;
	return (res);
}

