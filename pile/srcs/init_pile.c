#include "pile.h"

t_pile		*make_pile(int nb)
{
	t_pile	*a;

	if (!(a = (t_pile *)malloc(sizeof (t_pile *))))
		return (NULL);
	a->value = nb;
	a->next = NULL;
	return (a);
}

int		is_space(char c)
{
	if (c && ((c >= 9 && c <= 13) || c == ' '))
		return (1);
	return (0);
}

t_pile		*ft_atop(char *str, int *i)
{
	long	tot;
	long	m;

	m = 1;
	while (is_space(str[*i]))
		*i = *i + 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			m = -1;
		*i += 1;
	}
	tot = 0;
	if (!str[*i])
		return (NULL);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		tot = tot * 10 + (str[*i] - '0') * m;
		*i += 1;
		if (tot > 2147483647 || tot < -2147483648)
			return (NULL);
	}
	if (str[*i] && !is_space(str[*i]))
		return (NULL);
	return (make_pile ((int)tot));
}

t_pile	*get_pile_a(char *str)
{
	t_pile	*pa;
	t_pile	*next;
	int	i;

	if (!(pa = (t_pile *)malloc(sizeof (t_pile *))))
		return (NULL);
	i = 0;
	if (!(pa = ft_atop(str, &i)))
		return (free_pile(pa));
	while (str[i])
	{
		if (!(next = ft_atop(str, &i)) && str[i])
			return (free_pile(pa));
		add_back(pa, next);
	}
	return (pa);
}

int	count_pile_size(t_pile *pile)
{
	int	i;

	if (!pile)
		return (0);
	i = 1;
	while (pile->next)
	{
		i++;
		pile = pile->next;
	}
	return (i);
}

