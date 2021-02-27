#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_res {
	int	i;
	char	*str;
}	t_res;

char		*ft_joinchar(char *str, char c);
int		ft_strlen(char *str);
void		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
char		*ft_strdup(char *str);
