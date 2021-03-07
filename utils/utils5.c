#include "../ft_printf.h"

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