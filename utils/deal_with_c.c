#include "../ft_printf.h"

t_flag_i	c_with_neg_or_pos(t_flag flag, char *str, int i)
{
	t_flag_i	flag_i;

	if (flag.neg)
	{
		flag_i = c_with_neg(flag, str, i);
		i = flag_i.i;
		flag = flag_i.flag;
	}
	else
	{
		flag_i = c_with_pos(flag, str, i);
		i = flag_i.i;
		flag = flag_i.flag;
	}
	return (flag_i);
}


t_flag_i	c_with_neg(t_flag flag, char *str, int i)
{
	t_flag_i	flag_i;

	write(1, &str[ft_strlen(str)], 1);
	i++;
	flag.count++;
	while (--flag.width > 0)
	{
		flag.count++;
		i++;
		write(1, " ", 1);
	}
	flag_i.flag = flag;
	flag_i.i	= i;
	return (flag_i);
}

t_flag_i	c_with_pos(t_flag flag, char *str, int i)
{
	t_flag_i	flag_i;

	while (--flag.width > 0)
	{
		flag.count++;
		i++;
		write(1, " ", 1);
	}
	i++;
	flag.count++;
	write(1, &str[ft_strlen(str)], 1);
	flag_i.flag = flag;
	flag_i.i = i;
	return (flag_i);
}

t_proxy		deal_with_c(t_flag flag, t_res res, char *str)
{
	t_proxy		proxy;
	t_flag_i	flag_i;
	int			i;

	i = 0;
	flag_i = c_with_neg_or_pos(flag, str, i);
	flag = flag_i.flag;
	i = flag_i.i;
	res.i++;
	while (str[res.i] != '%' && (res.i + 1 < ft_strlen((char *)str)))
	{
		write(1, &str[res.i], 1);
		res.i++;
		flag.count++;
	}
	res.str = ft_join(res.str, "");
	proxy.res = res;
	proxy.flag = flag;
	return (proxy);
}