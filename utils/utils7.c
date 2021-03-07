#include "../ft_printf.h"

t_gvalue	get_c_value(va_list data, t_flag flag, t_gvalue render)
{
	t_jchar		joinc;

	joinc = ft_joinchar("", (char)va_arg(data, int), flag, 1);
	render.flag.len = joinc.len + render.flag.len;
	render.str = joinc.str;
	return (render);
}

char	*give_s_itoa(int nb)
{
	char	*s;
	int		i;

	s = malloc(sizeof(char) * (ft_intlen(nb) + 2));
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