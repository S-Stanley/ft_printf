/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:05:44 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:05:44 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strndup(char *str, int max)
{
	int		i;
	char	*s;

	i = -1;
	s = get_malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	if (max < 0)
		max = ft_strlen(str);
	while (str[++i] && i < max)
		s[i] = str[i];
	s[i] = '\0';
	free(str);
	return (s);
}

t_flag		init_flags(void)
{
	t_flag	flag;

	flag.width = 0;
	flag.right = 0;
	flag.sep = ' ';
	flag.precis = 0;
	flag.isprecision = 0;
	flag.iswidth = 0;
	flag.len = 0;
	flag.neg = 0;
	flag.flag = 0;
	flag.count = 0;
	flag.dash = 0;
	flag.ispts = 0;
	return (flag);
}

t_flag		re_init_flags(t_flag ex)
{
	t_flag	flag;

	flag.width = 0;
	flag.right = 0;
	flag.sep = ' ';
	flag.precis = 0;
	flag.isprecision = 0;
	flag.iswidth = 0;
	flag.len = 0;
	flag.neg = 0;
	flag.flag = 0;
	flag.count = ex.count;
	flag.dash = 0;
	flag.ispts = 0;
	return (flag);
}

char		*ft_strdup(char *str)
{
	char	*s;
	int		i;

	i = -1;
	s = get_malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

int			ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
