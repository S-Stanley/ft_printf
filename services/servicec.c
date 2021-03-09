/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servicec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:08:06 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/09 13:08:07 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*add_left_pos2(int size_min, char *s, char sep, int size)
{
	char	*s2;
	int		i;
	int		x;

	x = 0;
	i = 0;
	s2 = get_malloc(ft_strlen(s) + size_min + 1);
	if (ft_atoi(s) < 0 && sep == '0' && ft_strcmp(s, "%") != 0)
	{
		s2[i++] = '-';
		x = ft_atoi(s);
		free(s);
		if (x == -2147483648)
			s = ft_strdup("2147483648");
		else
			s = ft_itoa(x * -1);
		x = 0;
	}
	while (size-- > 0)
		s2[i++] = sep;
	while (s[x])
		s2[i++] = s[x++];
	s2[i] = '\0';
	free(s);
	return (s2);
}

char		*add_left_neg2(int size_min, int size, char sep, char *s)
{
	int		i;
	int		x;
	char	*s2;

	i = 0;
	x = 0;
	s2 = get_malloc(ft_strlen(s) + size_min + 1);
	if (ft_atoi(s) < 0 && sep == '0')
	{
		s2[i++] = '-';
		x = ft_atoi(s);
		free(s);
		s = ft_itoa(x * -1);
		x = 0;
	}
	while (s[x])
		s2[i++] = s[x++];
	while (size-- > 0)
		s2[i++] = sep;
	s2[i] = '\0';
	free(s);
	return (s2);
}

char		*add_left_n_else2(char *s, int size, char sep, int minus)
{
	char	*s2;
	int		x;
	int		i;

	x = 0;
	i = 0;
	s2 = get_malloc(ft_strlen(s) + size + 1);
	if (minus)
		s2[i++] = '-';
	while (size-- > 0)
		s2[i++] = sep;
	while (s[x])
		s2[i++] = s[x++];
	s2[i] = '\0';
	return (s2);
}
