/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:05:13 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:05:14 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (1);
	if (str[i] == '0')
		return (1);
	return (0);
}

int	ft_is_with(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	if (str[i] == '*')
		return (1);
	if (str[i - 1] == '0' || str[i - 1] == '-')
		return (1);
	return (0);
}

int	ft_is_prevision(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
		return (1);
	return (0);
}

int	ft_isletter(char *str)
{
	int		i;
	char	*flags;

	flags = ft_strdup("cspdiuxX%");
	i = 0;
	while (flags[i])
	{
		if (str[0] == flags[i])
		{
			free(flags);
			return (1);
		}
		i++;
	}
	free(flags);
	return (0);
}
