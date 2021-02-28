#include "ft_printf.h"

char		*ft_add_left(char *s, int size_min, char sep)
{
	int	size;
	char	*s2;
	int	i;
	int	x;

	i = 0;
	x = 0;
	size = size_min - ft_strlen(s);
	s2 = malloc(sizeof(char) * (ft_strlen(s) + size_min + 1));
	while (size-- > 0)
	{
		s2[i] = sep;
		i++;
	}
	while (s[x])
	{
		s2[i] = s[x];
		i++;
		x++;
	}
	s2[i] = '\0';
	return (s2);
}

t_width		get_width(char *str, t_res res, va_list data)
{
	t_width	width;

	width.value = 0;
	if (str[res.i] == '*')
	{
		width.value = va_arg(data, int);
		res.i++;
	}
	else
	{
		while (str[res.i] >= '1' && str[res.i] <= '9')
		{
			width.value = (width.value * 10) + (str[res.i] - 48);
			res.i++;
		}
	}
	width.i = res.i;
	return (width);
}
