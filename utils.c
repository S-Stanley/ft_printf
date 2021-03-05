#include "ft_printf.h"

int		check_ingredients(char c, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_count_hexa(int nb)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

char	*str_that_address(int nb)
{
	long int			container;
	char				tmp;
	unsigned long int	n;
	char				*str;
	int					i;

	i = -1;
	if (nb == 0)
		return (ft_strdup("0x0"));
	n = (unsigned long int)nb;
	container = 16;
	str = malloc(sizeof(char) * (ft_intlen(n) + 3));
	while (n / container >= 16)
		container = container * 16;
	str[++i] = '0';
	str[++i] = 'x';
	while (container > 0)
	{
		tmp = n / container + '0';
		if (tmp > '9')
		{
			tmp = tmp + 39;
			str[++i] = tmp;
		}
		else
			str[++i] = tmp;
		n = n % container;
		container = container / 16;
	}
	str[++i] = '\0';
	return (str);
}

int		unsigned_len(unsigned int nb)
{
	int		i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_putinsigned_int(int nbr)
{
	unsigned int	n;
	char			*s;
	int				i;

	n = (unsigned int)nbr;
	s = malloc(sizeof(char) * (unsigned_len(n) + 1));
	i = -1;
	if (n == 0 || n == 1)
		return (ft_strndup(ft_itoa(n), 2));
	while (n >= 1)
	{
		s[++i] = (n % 10) + '0';
		n = n / 10;
	}
	s[++i] = '\0';
	s = reverse_table(s);
	return (s);
}

char	*ft_itoa_hexa_min(int nbr)
{
	int				i;
	char			*s;
	int				minus;
	int				c;
	unsigned int	nb;

	nb = (unsigned int)nbr;
	if (nb == 0)
		return (ft_strdup("0"));
	i = 0;
	minus = 0;
	s = malloc(sizeof(char) * (ft_count_hexa(nb) + 2));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		nb = (unsigned int)-nb;
		minus = 1;
	}
	while (nb >= 1)
	{
		c = (nb % 16) + 48;
		if (c >= 58)
			c = c + 7 + 32;
		s[i] = c;
		i++;
		nb = nb / 16;
	}
	s[i] = '\0';
	s = reverse_table(s);
	if (minus)
		s = ft_join("-", s);
	return (s);
}

char	*ft_itoa_hexa_maj(int nbr)
{
	int				i;
	char			*s;
	int				minus;
	int				c;
	unsigned int	nb;

	nb = (unsigned int)nbr;
	if (nb == 0)
		return (ft_strdup("0"));
	i = 0;
	minus = 0;
	s = malloc(sizeof(char) * (ft_count_hexa(nb) + 2));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		minus = 1;
	}
	while (nb >= 1)
	{
		c = (nb % 16) + 48;
		if (c >= 58)
			c = c + 7;
		s[i] = c;
		i++;
		nb = nb / 16;
	}
	s[i] = '\0';
	s = reverse_table(s);
	if (minus)
		s = ft_join("-", s);
	return (s);
}

int		ft_atoi(char *str)
{
	int	nb;
	int	i;
	int	minus;

	minus = 1;
	nb = 0;
	i = 0;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	while (str[i])
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * minus);
}

char		*ft_strndup(char *str, int max)
{
	int	i;
	char	*s;

	i = -1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	while (str[++i] && i < max)
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

t_flag		init_flags()
{
	t_flag	flag;

	flag.width = 0;
	flag.right = 0;
	flag.sep = ' ';
	flag.precis = 0;
	flag.isprecision = 0;
	flag.iswidth = 0;
	flag.len = 0;
	return (flag);
}

char		*ft_strdup(char *str)
{
	char	*s;
	int	i;	

	i = -1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	while (str[++i])
		s[i] = str[i];
	s[i] = '\0';
	return (s);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putstr(char *str, t_flag flag)
{
	int	i;

	if (flag.len != 0 && flag.letter == 'c')
	{
		i = -1;
		while (++i < flag.len)
			write(1, &str[i], 1);
		return (i);
	}
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (ft_strlen(str));	
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
	t_jchar		joinc;
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
		render.str = str_that_address(va_arg(data, int));
	else if (c == 'u')
		render.str = ft_putinsigned_int(va_arg(data, int));
	else if (c == 'c')
	{		joinc = ft_joinchar("", (char)va_arg(data, int), flag, 1);
		render.flag.len = joinc.len;
		render.str = joinc.str;
	}
	else if (c == '%')
		render.str = ft_strdup("%");
	else
		render.str = ft_strdup("");
	return (render);
}

int		ft_intlen(int nb)
{
	int	i;

	i = 0;
	while (nb >= 1)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int	i;
	char	*s;
	int	minus;

	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == 2147483647)
		return (ft_strdup("2147483647"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	minus = 0;
	s = malloc(sizeof(char) * (ft_intlen(nb) + 2));
	if (!s)
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		minus = 1;
	}
	while (nb >= 1)
	{
		s[i] = (nb % 10) + 48;
		i++;
		nb = nb / 10;
	}
	s[i] = '\0';
	s = reverse_table(s);
	if (minus)
		s = ft_join("-", s);
	return (s);
}

char	*reverse_table(char *str)
{
	char	*s;
	int	i;
	int	x;

	i = 0;
	x = ft_strlen(str) - 1;
	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	while (x >= 0)
	{
		s[i] = str[x];
		i++;
		x--;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_join(char *s1, char *s2)
{
	int	i;
	int	x;
	char	*s;

	i = 0;
	x = 0;
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	return (s);
}

int		ft_find(char *str, char *to_find)
{
	int		i;
	int		x;
	int		keep;

	i = -1;
	while (str[++i])
	{
		x = 0;
		keep = i;
		while (to_find[x] == str[i])
		{
			i++;
			x++;
		}
		if (x == ft_strlen(to_find))
			return (1);
		else
			i = keep;
	}
	return (0);
}

char	*ft_clean(char *str, char *to_del)
{
	int		i;
	int		x;
	int		keep;
	char	*s;
	int		index;

	s = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	index = -1;
	while (str[i])
	{
		x = 0;
		keep = i;
		while (to_del[x] == str[i])
		{
			i++;
			x++;
		}
		if (x != ft_strlen(to_del))
			i = keep;
		s[++index] = str[i];
		i++;
	}
	s[++index] = '\0';
	return (s);
}

char	*put_it_first(char *str, char *to_move)
{
	char	*s;
	char	*s2;
	int		i;
	int		x;
	int		y;

	s2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	s = ft_clean(str, to_move);
	i = 0;
	x = 0;
	y = 0;
	while (s[i] == ' ')
	{
		s2[x] = s[i];
		x++;
		i++;
	}
	while (to_move[y])
	{
		s2[x] = to_move[y];
		x++;
		y++;
	}
	while (s[i])
	{
		s2[x] = s[i];
		x++;
		i++;
	}
	s2[x] = '\0';
	return (s2);
}