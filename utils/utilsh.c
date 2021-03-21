/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 04:20:10 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/09 04:20:11 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_join2(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*s;

	i = 0;
	x = 0;
	s = get_malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2[x])
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

char	*ft_make_it_neg(char *s)
{
	char 	*s2;
	int		i;
	int		x;

	s2 = get_malloc(ft_strlen(s) + 2);
	i = 0;
	x = 0;
	s2[x] = '-';
	x++;
	while (s[i])
	{
		s2[x] = s[i];
		x++;
		i++;
	}
	s2[x] = '\0';
	free(s);
	return (s2);
}