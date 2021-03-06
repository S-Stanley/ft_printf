/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:05:20 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:05:21 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flag_i	c_with_neg_or_pos(t_flag flag, char *str, int i)
{
	t_flag_i	flag_i;

	if (flag.neg)
	{
		flag_i = c_with_neg(flag, str, i);
		i = flag_i.i;
		flag = flag_i.flag;
	}
	else
	{
		flag_i = c_with_pos(flag, str, i);
		i = flag_i.i;
		flag = flag_i.flag;
	}
	return (flag_i);
}

t_flag_i	c_with_neg(t_flag flag, char *str, int i)
{
	t_flag_i	flag_i;

	write(1, &str[ft_strlen(str)], 1);
	i++;
	flag.count++;
	while (--flag.width > 0)
	{
		flag.count++;
		i++;
		write(1, " ", 1);
	}
	flag_i.flag = flag;
	flag_i.i = i;
	return (flag_i);
}

t_flag_i	c_with_pos(t_flag flag, char *str, int i)
{
	t_flag_i	flag_i;

	while (--flag.width > 0)
	{
		flag.count++;
		i++;
		write(1, " ", 1);
	}
	i++;
	flag.count++;
	write(1, &str[ft_strlen(str)], 1);
	flag_i.flag = flag;
	flag_i.i = i;
	return (flag_i);
}

t_proxy		deal_with_c(t_flag flag, t_res res, char *str)
{
	t_proxy		proxy;
	t_flag_i	flag_i;
	int			i;

	i = 0;
	flag_i = c_with_neg_or_pos(flag, str, i);
	flag = flag_i.flag;
	i = flag_i.i;
	res.i++;
	while (str[res.i] != '%' && (res.i + 1 < ft_strlen((char *)str)))
	{
		res.max++;
		res.str = ft_joinchar2(res.str, str[res.i]);
		res.i++;
		flag.count++;
	}
	res.str = ft_join(res.str, ft_strdup(""));
	proxy.res = res;
	proxy.flag = flag;
	return (proxy);
}

t_printer	return_it_now(t_flag flag, char *str, char *s, t_res res)
{
	t_printer	printer;

	if (ft_atoi(s) == 0 && flag.precis == 0 && flag.width == 0)
	{
		if (str[res.i - 1] == '.' || str[res.i - 2] == '.')
		{
			res.i++;
			printer.flag = flag;
			res.str = ft_strdup("");
			printer.res = res;
			printer.result = 1;
			return (printer);
		}
	}
	printer.result = 0;
	return (printer);
}
