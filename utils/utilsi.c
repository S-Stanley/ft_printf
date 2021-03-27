/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:34:57 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/27 09:34:58 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char		*ft_strdup_pass_null(char *str, int max)
{
	char	*s;
	int		i;

	i = 0;
	s = get_malloc(max + 1);
	while (max-- >= 0)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int			ft_putstrlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
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

int			ft_read_lst(t_x *res)
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
		free(res->s);
		free(res);
		res = tmp;
	}
	return (count);
}

t_x			*ft_lst_add_back(t_x *old, t_res res, t_flag flag)
{
	t_x		*new;
	t_x		*tmp;

	new = malloc(sizeof(t_x));
	if (flag.null && flag.letter == 'c' && flag.neg)
	{
		new->s = ft_strdup_pass_null(res.str, res.i);
	}
	else if (flag.null && flag.letter == 'c' && flag.width == 2)
	{
		new->s = ft_strdup_pass_null(res.str, res.i);
	}
	else
		new->s = ft_strdup(res.str);
	free(res.str);
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
