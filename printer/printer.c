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

t_printer	manage_c_pos(t_printer printer, t_flag flag)
{
	free(printer.res.str);
	printer.res.str = ft_strdup("");
	while (flag.width-- >= 0)
	{
		printer.res.str = ft_joinchar2(printer.res.str, ' ');
		printer.res.max++;
	}
	if (printer.flag.null)
	{
		if (ft_strcmp("", printer.res.str))
		{
			if (flag.width == 2)
				printer.res.str = ft_joinchar_null(printer.res.str, printer.res.max, 1);
			else
				printer.res.str = ft_joinchar_null(printer.res.str, printer.res.max, 0);
		}
		else
		{
			printer.res.str = ft_joinchar2(printer.res.str, '\0');
			printer.res.max++;
		}
		printer.res.max++;
	}
	return (printer);
}

t_printer	manage_c_neg(t_printer printer, t_flag flag)
{
	char	*str;
	int		i;

	i = 0;
	str = get_malloc(flag.width + 2);
	str[i] = '\0';
	i++;
	printer.res.max++;
	while (flag.width-- > 0)
	{
		str[i] = ' ';
		i++;
		printer.res.max++;
	}
	str[i] = '\0';
	free(printer.res.str);
	printer.res.str = str;
	printer.res.max++;
	return (printer);
}

t_printer	manage_c(t_printer printer, t_flag flag)
{
	char		*tmp;

	tmp = ft_strdup(printer.s);
	flag.width--;
	if (!flag.neg)
		printer = manage_c_pos(printer, flag);
	if (flag.neg)
		printer = manage_c_neg(printer, flag);
	free(printer.s);
	free(tmp);
	printer.res.i++;
	return (printer);
}

char		*manage_p_null(char *s, t_flag flag)
{
	free(s);
	if (flag.ispts)
		s = ft_strdup("0x");
	else
		s = ft_strdup("0x0");
	return (s);
}

int			check_OX(t_printer printer, t_flag flag)
{
	if (printer.flag.letter == 'p' && ft_find(printer.s, "0x"))
	{
		if (!flag.neg && !flag.dash)
			return (1);
	}
	return(0);
}

t_printer	printer_proxy(t_flag flag, char *str, char *s, t_res res)
{
	t_printer	printer;

	flag.letter = str[res.i];
	if (flag.letter == 'p' && flag.precis != 0 && flag.isprecision == 1)
		flag.precis = flag.precis + 2;
	if (flag.letter == 'p' && !s)
		s = manage_p_null(s, flag);
	if (flag.letter != 'p' && flag.ispts == 1)
		flag.isprecision = 1;
	printer = manage_precis(flag, s, str, res);
	printer = manage_width(printer.flag, printer.s, printer.res);
	flag = printer.flag;
	res = printer.res;
	if (check_OX(printer, flag))
		printer.s = put_it_first(printer.s, "0x");
	if (printer.flag.null)
		printer = manage_c(printer, flag);
	else
	{
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
	if (flag.precis == 0 && str[res.i] == 'c')
		flag.precis = 1;
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
