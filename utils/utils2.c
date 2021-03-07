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