#include "../ft_printf.h"

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

char	*ft_putinsigned_int(unsigned int n)
{
	char			*s;
	int				i;

	s = get_malloc(unsigned_len(n) + 1);
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
	char			*s;
	int				minus;
	unsigned int	nb;

	s = NULL;
	nb = (unsigned int)nbr;
	if (nb == 0)
		return (ft_strdup("0"));
	minus = 0;
	if (nb < 0)
	{
		nb = (unsigned int)-nb;
		minus = 1;
	}
	s = give_s_of_itoa_hexa(nb, 32);
	if (minus)
		s = ft_join("-", s);
	return (s);
}

char	*ft_itoa_hexa_maj(int nbr)
{
	char			*s;
	int				minus;
	unsigned int	nb;

	nb = (unsigned int)nbr;
	if (nb == 0)
		return (ft_strdup("0"));
	minus = 0;
	if (nb < 0)
	{
		nb = -nb;
		minus = 1;
	}
	s = give_s_of_itoa_hexa(nb, 0);
	if (minus)
		s = ft_join("-", s);
	return (s);
}

long long	ft_atoi(char *str)
{
	long long int	nb;
	int				i;
	int				minus;

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