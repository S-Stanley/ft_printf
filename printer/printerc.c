/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:50:54 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/27 09:50:55 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_printer	manage_precis(t_flag flag, char *s, char *str, t_res res)
{
	t_printer	printer;

	if (flag.isprecision && flag.letter != 'c' && flag.letter != '%')
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

char		*manage_p_null(char *s, t_flag flag)
{
	free(s);
	if (flag.ispts)
		s = ft_strdup("0x");
	else
		s = ft_strdup("0x0");
	return (s);
}

int			check_ox(t_printer printer, t_flag flag)
{
	if (printer.flag.letter == 'p' && ft_find(printer.s, "0x"))
	{
		if (!flag.neg && !flag.dash)
			return (1);
	}
	return (0);
}
