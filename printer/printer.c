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
			s = ft_strdup_and_free("0x", s);
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

t_printer	manage_width(t_flag flag, char *s, t_res res)
{
	t_printer printer;

	if (flag.width)
	{
		if (ft_atoi(s) == 0 && flag.width == 0)
			s = ft_strdup_and_free("", s);
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

char		*ft_join_pass_null(char *s1, char *s2, int max, int max2)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	x = 0;
	s = get_malloc(max + ft_strlen(s2) + 1);
	while (max-- > 0)
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[x] && x < max2)
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
	t_printer	printer;

	flag.letter = str[res.i];
	if (flag.letter == 'p' && flag.precis != 0 && flag.isprecision == 1)
		flag.precis = flag.precis + 2;
	if (flag.letter == 'p' && !s)
	{
		free(s);
		if (flag.ispts)
			s = ft_strdup("0x");
		else
			s = ft_strdup("0x0");
	}
	if (flag.letter != 'p' && flag.ispts == 1)
		flag.isprecision = 1;
	printer = manage_precis(flag, s, str, res);
	printer = manage_width(printer.flag, printer.s, printer.res);
	flag = printer.flag;
	res = printer.res;
	if (printer.flag.letter == 'p' && ft_find(printer.s, "0x") && !flag.neg && !flag.dash)
		printer.s = put_it_first(printer.s, "0x");
	if (printer.flag.null)
	{
		char	*tmp;
		tmp = ft_strdup(printer.s);
		flag.width--;
		if (!flag.neg)
		{
			// free(printer.res.str);
			printer.res.str = ft_strdup("");
			while (flag.width-- >= 0)
			{
				printer.res.str = ft_joinchar2(printer.res.str, ' ');
				// printer.res.str = ft_joinchar_pass_null(ft_strdup(""), ' ', printer.res.max, flag.count_null);
				printer.res.max++;
			}
			if (printer.flag.null)
			{
				printer.res.str = ft_joinchar_null(printer.res.str, printer.res.max);
				printer.res.max++;
			}
			free(tmp);
		}
		if (flag.neg)
		{
			int		count;

			count = ft_strlen(tmp) -1 -1;
			printer.res.str = ft_joinchar2(printer.res.str, '\0');
			printer.res.max++;
			printer.res.str = ft_join_pass_null(printer.res.str, tmp, printer.res.max, ft_strlen(tmp) - 1);
			printer.res.max = printer.res.max + count;
		}
		free(printer.s);
		// printer.res.max++;
		printer.res.i++;
	}
	else
	{
		// printer.res.str = ft_join2(printer.res.str, printer.s);
		printer.res.str = printer.s;
		printer.res.i++;
	}
	if (!printer.flag.null)
		printer.res.max = printer.res.max + ft_strlen(printer.res.str);
	return (printer);
}

t_printer	ft_printer(char *str, t_res res, va_list data, t_flag flag)
{
	t_gvalue	gvalue;
	t_printer	printer;
	
	if (str[res.i] == '.' && flag.precis == 0)
		res.i++;
	gvalue = get_value(str[res.i], data, flag);
	flag = gvalue.flag;
	if (gvalue.str && gvalue.str[0] == '\0' && gvalue.str[1] == '\0' && str[res.i] == 'c')
	{
		flag.null = 1;
		flag.count_null++;
	}
	if (str[res.i] == 'p' && !gvalue.str)
		return (printer_proxy(flag, str, gvalue.str, res));
	printer = return_it_now(flag, str, gvalue.str, res);
	if (printer.result)
	{
		free(gvalue.str);
		return (printer);
	}
	printer = printer_proxy(flag, str, gvalue.str, res);
	return (printer);
}
