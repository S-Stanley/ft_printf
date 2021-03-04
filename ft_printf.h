#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_res {
	int	i;
	char	*str;
}	t_res;

typedef struct s_flag {
	int		isprecision;
	int		width;
	int		i;
	int		right;
	char	sep;
	int		precis;
	char	letter;
	int		iswidth;
}	t_flag;

int			ft_printf(const char *str, ...);
t_res		ft_proxy(char *str, t_res res, va_list data);

char		*ft_joinchar(char *str, char c);
int			ft_strlen(char *str);
void		ft_putstr(char *str);
char		*ft_strdup(char *str);
char		*get_value(char c, va_list data);
char		*ft_join(char *s1, char *s2);
char		*ft_itoa(int nb);
char		*reverse_table(char *str);
int			ft_intlen(int nb);
t_flag		init_flags();
char		*ft_strndup(char *str, int max);
int			ft_atoi(char *str);
char		*ft_itoa_hexa_min(int nbr);
char		*ft_itoa_hexa_maj(int nbr);
char		*ft_putinsigned_int(int nbr);
char		*str_that_address(int nb);
int			ft_count_hexa(int nb);
int			ft_strcmp(char *s1, char *s2);
char		*get_string(va_list data);
int			check_ingredients(char c, char *str);

t_flag		get_width(char *str, t_res res, va_list data, t_flag flag);
char		*ft_add_left(char *s, int size_min, char sep);
char		*ft_add_right(char *s, int size_min, char sep);
t_flag		ft_get_flag(t_flag flag, t_res res, char *str);
t_res		ft_printer(char *str, t_res res, va_list data, t_flag flag);
t_flag		ft_get_precision(char *str, t_res res, va_list data, t_flag flag);
char		*ft_add_left_n(char *s, int size_min, char sep, char letter);
// char		*update_with_precis(char *str, t_res res, t_flag flag, char *s);
// char		*update_with_width(char *str, t_res res, t_flag flag, char *s);

int			ft_is_flag(char *str);
int			ft_is_with(char *str);
int			ft_is_prevision(char *str);
int			ft_isletter(char *str);
