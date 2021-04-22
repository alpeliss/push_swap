#include "pile.h"

t_pile	*free_pile(t_pile *a)
{
	t_pile	*tmp;

	if (!a)
		return (NULL);
	tmp = a->next;
	while (a)
	{
		free(a);
		a = tmp;
		if (a)
			tmp = a->next;
	}
	return (NULL);
}

t_pile	*add_back(t_pile *a, t_pile *b)
{
	t_pile	*tmp;

	if (!a)
		return (b);
	tmp = a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b;
	return (b);
}

int	check_doublons(t_pile *a)
{
	t_pile	*tmp;

	if (!a)
		return (1);
	while (a->next)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->value == a->value)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

void	print_piles(t_pile *a, t_pile *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("[%11d]", a->value);
			a = a->next;
		}
		else
			printf("[           ]");
		if (b)
		{
			printf("[%11d]", b->value);
			b = b->next;
		}
		else
			printf("[           ]");
		printf("\n");
	}
	printf("      a            b     \n\n");
}

int	check_tri(t_pile *a, t_pile *b)
{
	if (b)
		return (0);
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
