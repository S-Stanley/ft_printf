/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:04:28 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:04:33 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		flag = ft_get_preci(str, res, data, flag);
		res.i = flag.i;
	}
	printer = ft_printer(str, res, data, flag);
	render.res = printer.res;
	render.flag = printer.flag;
	return (render);
}

t_proxy		printf_true(t_proxy render, const char *str, va_list data)
{
	t_res 	res;
	t_flag	flag;
	t_x		*prt;

	prt = NULL;
	res = render.res;
	prt = render.prt;
	flag = render.flag;
	res.str = NULL;
	flag = re_init_flags(flag);
	render = ft_proxy((char *)str, res, data, flag);
	prt = ft_lst_add_back(prt, render.res, render.flag);
	render.res.max = 1;
	render.prt = prt;
	return (render);
}

t_proxy		printf_false(t_res res, t_flag flag, t_x *prt, const char *str)
{
	t_proxy render;

	res.str = ft_joinchar2(ft_strdup(""), str[res.i]);
	res.i++;
	res.max++;
	flag.null = 0;
	prt = ft_lst_add_back(prt, res, flag);
	res.max = 0;
	render.res = res;
	render.flag = flag;
	render.prt = prt;
	return (render);
}

int			ft_printf(const char *str, ...)
{
	va_list	data;
	t_proxy	render;

	va_start(data, str);
	render.res = init_res();
	render.flag = init_flags();
	render.prt = NULL;
	while (str[render.res.i])
	{
		if (str[render.res.i] == '%')
			render = printf_true(render, str, data);
		else
			render = printf_false(render.res, render.flag, render.prt, str);
	}
	va_end(data);
	return (ft_read_lst(render.prt));
}
