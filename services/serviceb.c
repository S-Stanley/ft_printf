/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serviceb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:38:46 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:38:47 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_flag		ft_get_preci(char *str, t_res res, va_list data, t_flag flag)
{
	res.i++;
	flag.isprecision = 1;
	if (str[res.i] == '*')
	{
		flag.precis = va_arg(data, int);
		res.i++;
	}
	else
	{
		while (str[res.i] >= '0' && str[res.i] <= '9')
		{
			flag.precis = (flag.precis * 10) + (str[res.i] - 48);
			res.i++;
		}
	}
	flag.i = res.i;
	return (flag);
}

t_flag		ft_get_flag(t_flag flag, t_res res, char *str)
{
	if (str[res.i] == '0')
	{
		flag.sep = '0';
		res.i++;
		flag.flag = '0';
	}
	if (str[res.i] == '-')
	{
		flag.right = 1;
		res.i++;
		flag.neg = 1;
	}
	flag.i = res.i;
	return (flag);
}

char		*ft_add_right(char *s, int size_min, char sep)
{
	int		size;
	char	*s2;
	int		i;

	i = 0;
	size = size_min - ft_strlen(s);
	s2 = get_malloc(ft_strlen(s) + size_min + 1);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	while (size-- > 0)
		s2[i++] = sep;
	s2[i] = '\0';
	free(s);
	return (s2);
}

char		*add_left_pos(int size_min, char *s, char sep)
{
	int		size;
	char	*s2;

	size = size_min - ft_strlen(s);
	s2 = add_left_pos2(size_min, s, sep, size);
	return (s2);
}

char		*add_left_neg(int size_min, char *s, char sep)
{
	int		size;
	char	*s2;

	if (size_min < 0)
		size_min = -size_min;
	size = size_min - ft_strlen(s);
	s2 = add_left_neg2(size_min, size, sep, s);
	return (s2);
}
