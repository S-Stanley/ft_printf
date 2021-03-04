#include "ft_printf.h"

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
	if (str[i] == '-')
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return (1);
	if (str[i] == '*')
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
	int	i;
	char	*flags;

	flags = ft_strdup("cspdiuxX%");
	i = 0;
	while (flags[i])
	{
		if (str[0] == flags[i])
			return (1);
		i++;
	}
	return (0);
}
