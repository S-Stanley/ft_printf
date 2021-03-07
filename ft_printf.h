#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_res {
	int		i;
	char	*str;
}				t_res;

typedef struct	s_flag {
	int		isprecision;
	int		width;
	int		i;
	int		right;
	char	sep;
	int		precis;
	char	letter;
	int		iswidth;
	int		len;
	int 	neg;
	char	flag;
	int		count;
}				t_flag;

typedef struct	s_proxy {
	t_res 	res;
	t_flag	flag;
}				t_proxy;

typedef struct	s_jchar {
	char	*str;
	int		len;
}				t_jchar;

typedef struct	s_gvalue {
	char	*str;
	t_flag	flag;
}				t_gvalue;

typedef struct	s_printer {
	t_res	res;
	t_flag	flag;
}				t_printer;

int			ft_printf(const char *str, ...);
t_proxy		ft_proxy(char *str, t_res res, va_list data, t_flag flag);
t_jchar		ft_joinchar(char *str, char c, t_flag flag, int si);
int			ft_strlen(char *str);
int 		ft_putstr(char *str, t_flag flag);
char		*ft_strdup(char *str);
t_gvalue	get_value(char c, va_list data, t_flag flag);
char		*ft_join(char *s1, char *s2);
char		*ft_itoa(int nb);
char		*reverse_table(char *str);
int			ft_intlen(int nb);
t_flag		init_flags();
t_flag		re_init_flags(t_flag ex);
char		*ft_strndup(char *str, int max);
long long	ft_atoi(char *str);
char		*ft_itoa_hexa_min(int nbr);
char		*ft_itoa_hexa_maj(int nbr);
char		*ft_putinsigned_int(unsigned int n);
char		*str_that_address(unsigned long long n);
int			ft_count_hexa(int nb);
int			ft_strcmp(char *s1, char *s2);
char		*get_string(va_list data);
int			check_ingredients(char c, char *str);
int			ft_find(char *str, char *to_find);
char		*put_it_first(char *str, char *to_move);
char		*ft_joinchar2(char *str, char c);
int			ft_isnum(char c);
t_res		init_res(void);
t_flag		get_width(char *str, t_res res, va_list data, t_flag flag);
char		*ft_add_left(char *s, int size_min, char sep);
char		*ft_add_right(char *s, int size_min, char sep);
t_flag		ft_get_flag(t_flag flag, t_res res, char *str);
t_printer	ft_printer(char *str, t_res res, va_list data, t_flag flag);
t_flag		ft_get_precision(char *str, t_res res, va_list data, t_flag flag);
char		*ft_add_left_n(char *s, int size_min, char sep, char letter);
int			ft_is_flag(char *str);
int			ft_is_with(char *str);
int			ft_is_prevision(char *str);
int			ft_isletter(char *str);

#endif