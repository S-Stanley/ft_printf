/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:06:15 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:37:51 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_gvalue	get_c_value(va_list data, t_gvalue render)
{
	t_jchar		joinc;

	joinc = ft_joinchar(ft_strdup(""), (char)va_arg(data, int), 1);
	render.flag.len = joinc.len + render.flag.len;
	render.str = joinc.str;
	return (render);
}

char		*give_s_itoa(int nb)
{
	char	*s;
	int		i;

	s = get_malloc(ft_intlen(nb) + 2);
	i = 0;
	while (nb >= 1)
	{
		s[i] = (nb % 10) + 48;
		i++;
		nb = nb / 10;
	}
	s[i] = '\0';
	s = reverse_table(s);
	return (s);
}

char		*get_malloc(int size)
{
	char	*s;

	s = malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	return (s);
}

int			ft_isnum_plus(t_flag flag)
{
	if (flag.precis < 0 && flag.right == 0 && flag.flag == '0')
		return (1);
	return (0);
}

char		*ft_strdup_and_free(char *str, char *to_free)
{
	char	*s;
	int		i;

	i = -1;
	free(to_free);
	s = get_malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}
