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

char		*ft_strdup_pass_null(char *str, int max)
{
	char	*s;
	int		i;

	i = 0;
	s = get_malloc(max + 1);
	while (max-- > 0)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

t_x			*ft_lst_add_back(t_x *old, t_res res, t_flag flag)
{
	t_x		*new;
	t_x		*tmp;

	new = malloc(sizeof(t_x));
	// if (flag.null)
	// 	new->s = ft_strdup_pass_null(res.str, res.i);
	// else
	// 	new->s = ft_strdup(res.str);
	new->s = ft_strdup(res.str);
	new->i = res.max;
	new->special = flag.null;
	new->next = NULL;
	if (!old)
		return (new);
	tmp = old;
	while (old->next)
		old = old->next;
	old->next = new;
	return (tmp);
}

int			ft_putstrlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return(i);
}

int			weird_print(char *str, int max)
{
	int		i;

	i = 0;
	while (max-- > 1)
	{
		if (str[i] == '\0')
			write(1, "\0", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int 		ft_read_lst(t_x *res)
{
	t_x		*tmp;
	int		count;

	count = 0;
	while (res)
	{
		tmp = res->next;
		if (res->special)
			count = count + weird_print(res->s, res->i);
		else
			count = count + ft_putstrlen(res->s);
		// printf("%s\n", res->s);
		// free(res->s);
		// free(res);
		// res = res->next;
		res = tmp;
	}
	return (count);
}

int			ft_printf(const char *str, ...)
{
	va_list	data;
	t_res	res;
	t_flag	flag;
	t_proxy	render;
	t_x		*prt;

	va_start(data, str);
	res = init_res();
	flag = init_flags();
	prt = NULL;
	while (str[res.i])
	{
		if (str[res.i] == '%')
		{
			flag = re_init_flags(flag);
			render = ft_proxy((char *)str, res, data, flag);
			prt = ft_lst_add_back(prt, render.res, render.flag);
			res = render.res;
			res.max = 1;
			flag = render.flag;
		}
		else
		{
			res.str = ft_joinchar2(ft_strdup(""), str[res.i]);
			res.i++;
			res.max++;
			prt = ft_lst_add_back(prt, res, flag);
			free(res.str);
			res.str = ft_strdup("");
			res.max = 0;
		}
	}
	va_end(data);
	return (ft_read_lst(prt));
	// return (ft_putstr(res.str, flag, res.max));
}
