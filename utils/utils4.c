#include "../ft_printf.h"

int		ft_putstr(char *str, t_flag flag)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (ft_strlen(str) + flag.count);
}

char	*ft_joinchar2(char *str, char c)
{
	int		i;
	char	*s;

	i = -1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = c;
	s[++i] = '\0';
	return (s);
}

t_jchar	ft_joinchar(char *str, char c, t_flag flag, int si)
{
	int		i;
	char	*s;
	t_jchar	render;

	i = -1;
	render.len = 0;
	s = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!s)
	{
		render.str = NULL;
		return (render);
	}
	while (str[++i])
		s[i] = str[i];
	if (!c && si == 1)
		render.len = 1;
	s[i] = c;
	s[++i] = '\0';
	render.str = s;
	return (render);
}

char	*get_string(va_list data)
{
	char	*s;

	s = va_arg(data, char *);
	if (!s)
		return (ft_strdup("(null)"));
	return (s);
}

t_gvalue	get_value(char c, va_list data, t_flag flag)
{
	t_gvalue	render;

	render.flag = flag;
	if (c == 's')
		render.str = get_string(data);
	else if (c == 'd' || c == 'i')
		render.str = ft_itoa(va_arg(data, int));
	else if (c == 'x')
		render.str = ft_itoa_hexa_min(va_arg(data, int));
	else if (c == 'X')
		render.str = ft_itoa_hexa_maj(va_arg(data, int));
	else if (c == 'p')
		render.str = str_that_address(va_arg(data, unsigned long long));
	else if (c == 'u')
		render.str = ft_putinsigned_int(va_arg(data, unsigned int));
	else if (c == 'c')
		return (get_c_value(data, flag, render));
	else if (c == '%')
		render.str = ft_strdup("%");
	else
		render.str = ft_strdup("");
	return (render);
}