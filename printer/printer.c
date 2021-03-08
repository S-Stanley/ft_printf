/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:05:02 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:05:03 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printer	return_it_now(t_flag flag, char *str, char *s, t_res res)
{
	t_printer	printer;

	if (ft_atoi(s) == 0 && flag.precis == 0 && flag.width == 0)
	{
		if (str[res.i - 1] == '.' || str[res.i - 2] == '.')
		{
			res.i++;
			printer.flag = flag;
			printer.res = res;
			printer.result = 1;
			return (printer);
		}
	}
	printer.result = 0;
	return (printer);
}

t_printer	manage_precis(t_flag flag, char *s, char *str, t_res res)
{
	t_printer	printer;

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
			if (ft_isnum(flag.letter) && ft_isnum_plus(flag))
				flag.sep = '0';
			else
				flag.sep = ' ';
		}
	}
	printer.flag = flag;
	printer.res = res;
	printer.s = s;
	return (printer);
}

t_printer	manage_width(t_flag flag, char *s, char *str, t_res res)
{
	t_printer printer;

	if (flag.width)
	{
		if (ft_atoi(s) == 0 && flag.width == 0)
			s = ft_strdup("");
		if (flag.right)
			s = ft_add_right(s, flag.width, flag.sep);
		else
			s = ft_add_left(s, flag.width, flag.sep);
	}
	printer.res = res;
	printer.flag = flag;
	printer.s = s;
	return (printer);
}

char	*ft_join2(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	x = 0;
	s = get_malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[x])
	{
		s[i] = s2[x];
		x++;
		i++;
	}
	s[i] = '\0';
	free(s1);
	free(s2);
	return (s);
}


t_printer	printer_proxy(t_flag flag, char *str, char *s, t_res res)
{
	t_proxy		proxy;
	t_printer	printer;

	flag.letter = str[res.i];
	if (flag.letter == 'p' && flag.precis != 0)
		flag.precis = flag.precis + 2;
	printer = manage_precis(flag, s, str, res);
	printer = manage_width(printer.flag, printer.s, str, printer.res);
	flag = printer.flag;
	res = printer.res;
	if (printer.flag.letter == 'p' && ft_find(printer.s, "0x"))
		printer.s = put_it_first(printer.s, "0x");
	if (printer.flag.len != 0 && printer.flag.letter == 'c')
	{
		proxy = deal_with_c(printer.flag, printer.res, str);
		printer.flag = proxy.flag;
		printer.res = proxy.res;
	}
	else
	{
		printer.res.str = ft_join2(printer.res.str, printer.s);
		printer.res.i++;
	}
	return (printer);
}

t_printer	ft_printer(char *str, t_res res, va_list data, t_flag flag)
{
	char		*s;
	t_gvalue	gvalue;
	t_printer	printer;
	int			i;

	if (str[res.i] == '.' && flag.precis == 0)
		res.i++;
	gvalue = get_value(str[res.i], data, flag);
	s = gvalue.str;
	flag = gvalue.flag;
	printer = return_it_now(flag, str, s, res);
	if (printer.result)
		return (printer);
	printer = printer_proxy(flag, str, s, res);
	return (printer);
}
