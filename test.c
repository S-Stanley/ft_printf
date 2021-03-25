#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef	struct	s_x{
	char		*s;
	struct s_x	*next;
}				t_x;

t_x			*ft_lst_add_back(t_x *old, char *str)
{
	t_x		*new;
	t_x		*tmp;

	new = malloc(sizeof(t_x));
	new->s = strdup(str);
	new->next = NULL;
	if (!old)
		return (new);
	tmp = old;
	while (old->next)
	{
		old = old->next;
	}
	old->next = new;
	return (tmp);
}

void		ft_read_lst(t_x *res)
{
	t_x		*tmp;

	while (res)
	{
		tmp = res->next;
		printf("%s\n", res->s);
		free(res->s);
		free(res);
		res = res->next;
		res = tmp;
	}
}

int main(void)
{
	t_x		*res;

	res = NULL;
	res = ft_lst_add_back(res, "Salut");
	res = ft_lst_add_back(res, strdup("Ça va ?"));
	res = ft_lst_add_back(res, strdup("Hello"));
	ft_read_lst(res);
	return (0);
}