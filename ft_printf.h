#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_res {
	int	i;
	char	*str;
}	t_res;

int             ft_printf(const char *str, ...);
t_res		ft_proxy(char *str, t_res res, va_list data);

char		*ft_joinchar(char *str, char c);
int		ft_strlen(char *str);
void		ft_putstr(char *str);
char		*ft_strdup(char *str);
char		*get_value(char c, va_list data);
char		*ft_join(char *s1, char *s2);

int		ft_is_flag(char *str);
int		ft_is_with(char *str);
int		ft_is_prevision(char *str);
int		ft_isletter(char *str);
