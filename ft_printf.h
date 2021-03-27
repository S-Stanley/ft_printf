/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 18:04:50 by sserbin           #+#    #+#             */
/*   Updated: 2021/03/07 18:04:52 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_container {
	int				i;
	long int		container;
}				t_container;

typedef struct	s_x {
	int			i;
	char		*s;
	int			special;
	struct s_x	*next;
}				t_x;
typedef struct	s_res {
	int		i;
	char	*str;
	int		max;
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
	int		neg;
	char	flag;
	int		count;
	int		dash;
	int		ispts;
	int		null;
	int		count_null;
}				t_flag;

typedef struct	s_proxy {
	t_res	res;
	t_flag	flag;
	t_x		*prt;
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
	int		result;
	char	*s;
	char	*str;
}				t_printer;

typedef struct	s_flag_i {
	t_flag	flag;
	int		i;
}				t_flag_i;

int				ft_printf(const char *str, ...);
t_proxy			ft_proxy(char *str, t_res res, va_list data, t_flag flag);
t_jchar			ft_joinchar(char *str, char c, int si);
int				ft_strlen(char *str);
int				ft_putstr(char *str, t_flag flag, int max);
char			*ft_strdup(char *str);
t_gvalue		get_value(char c, va_list data, t_flag flag);
char			*ft_join(char *s1, char *s2);
char			*ft_itoa(int nb);
char			*reverse_table(char *str);
int				ft_intlen(int nb);
t_flag			init_flags();
t_flag			re_init_flags(t_flag ex);
char			*ft_strndup(char *str, int max);
long long		ft_atoi(char *str);
char			*ft_itoa_hexa_min(int nbr);
char			*ft_itoa_hexa_maj(int nbr);
char			*ft_putinsigned_int(unsigned int n);
char			*str_that_address(unsigned long long n);
int				ft_count_hexa(int nb);
int				ft_strcmp(char *s1, char *s2);
char			*get_string(va_list data);
int				check_ingredients(char c, char *str);
int				ft_find(char *str, char *to_find);
char			*put_it_first(char *str, char *to_move);
char			*ft_joinchar2(char *str, char c);
int				ft_isnum(char c);
t_res			init_res(void);
t_flag			get_width(char *str, t_res res, va_list data, t_flag flag);
char			*ft_add_left(char *s, int size_min, char sep);
char			*ft_add_right(char *s, int size_min, char sep);
t_flag			ft_get_flag(t_flag flag, t_res res, char *str);
t_printer		ft_printer(char *str, t_res res, va_list data, t_flag flag);
t_flag			ft_get_preci(char *str, t_res res, va_list data, t_flag flag);
char			*ft_add_left_n(char *s, int size_min, char sep, char letter);
int				ft_is_flag(char *str);
int				ft_is_with(char *str);
int				ft_is_prevision(char *str);
int				ft_isletter(char *str);
t_proxy			deal_with_c(t_flag flag, t_res res, char *str);
t_flag_i		c_with_pos(t_flag flag, char *str, int i);
t_flag_i		c_with_neg(t_flag flag, char *str, int i);
t_flag_i		c_with_neg_or_pos(t_flag flag, char *str, int i);
t_printer		printer_proxy(t_flag flag, char *str, char *s, t_res res);
t_printer		manage_width(t_flag flag, char *s, t_res res);
t_printer		manage_precis(t_flag flag, char *s, char *str, t_res res);
t_printer		return_it_now(t_flag flag, char *str, char *s, t_res res);
char			*add_left_neg(int size_min, char *s, char sep);
char			*add_left_pos(int size_min, char *s, char sep);
char			*add_left_n_else(char *s, int size, char sep, char letter);
char			*address_exception(unsigned long long n);
char			*give_s_of_itoa_hexa(unsigned int nb, int add);
t_gvalue		get_c_value(va_list data, t_gvalue render);
char			*give_s_itoa(int nb);
char			*get_malloc(int size);
int				ft_isnum_plus(t_flag flag);
char			*ft_join2(char *s1, char *s2);
char			*ft_strdup_and_free(char *str, char *to_free);
char			*add_left_pos2(int size_min, char *s, char sep, int size);
char			*add_left_neg2(int size_min, int size, char sep, char *s);
char			*add_left_n_else2(char *s, int size, char sep, int minus);
char			*ft_make_it_neg(char *s);
char			*jcn(char *str, int max, int add);
char			*ft_joinchar_pass_null(char *str, char c, int max, int add);
t_x				*ft_lst_add_back(t_x *old, t_res res, t_flag flag);
int				ft_read_lst(t_x *res);
t_container		get_container_value(unsigned long long n);
char			*manage_p_null(char *s, t_flag flag);
int				check_ox(t_printer printer, t_flag flag);

#endif
