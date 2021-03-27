/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:05:26 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:05:27 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_isnum(char c)
{
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'u')
		return (1);
	return (0);
}

int				check_ingredients(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int				ft_count_hexa(int nb)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

t_container		get_container_value(unsigned long long n)
{
	t_container		res;

	res.container = 16;
	res.i = 0;
	while (n / res.container >= 16)
	{
		res.i++;
		res.container = res.container * 16;
	}
	return (res);
}

char			*str_that_address(unsigned long long n)
{
	char				tmp;
	char				*str;
	t_container			res;

	if (!n)
		return (NULL);
	if (n == 0 || n == 1)
		return (address_exception(n));
	res = get_container_value(n);
	str = get_malloc(res.i + 100);
	res.i = -1;
	while (res.container > 0)
	{
		tmp = n / res.container + '0';
		if (tmp > '9')
			str[++res.i] = tmp + 39;
		else
			str[++res.i] = tmp;
		n = n % res.container;
		res.container = res.container / 16;
	}
	str[++res.i] = '\0';
	return (ft_join(ft_strdup("0x"), str));
}
