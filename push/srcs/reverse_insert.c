#include "push_swap.h"

static int	find_min_val(t_pile *pa)
{
	int	min_val;

	min_val = pa->value;
	while (pa)
	{
		if (pa->value < min_val)
			min_val = pa->value;
		pa = pa->next;
	}
	return (min_val);
}

int	find_sep(t_piles *piles, t_pile *pa, int place)
{
	int	min_val;
	int	next_min;
	int	nb_under;

	nb_under = 1;
	min_val = find_min_val(pa);
	while (nb_under < place && nb_under < piles->size_pa)
	{
		pa = ((t_piles *)piles)->pa;
		next_min = min_val;
		while (pa)
		{
			if (pa->value > min_val
				&& (pa->value < next_min || next_min == min_val))
				next_min = pa->value;
			pa = pa->next;
		}
		nb_under++;
		min_val = next_min;
	}
	return (min_val);
}

static	int	find_closer_mini(t_piles *piles, t_pile *pa, int *min_pos, int sep)
{
	int	pos;
	int	min_val;

	pos = 0;
	min_val = 0;
	while (pa)
	{
		if (pa->value <= sep
			&& (*min_pos == -1 || (piles->size_pa - pos < *min_pos)))
		{
			*min_pos = pos;
			min_val = pa->value;
		}
		pos++;
		pa = pa->next;
	}
	return (min_val);
}

static int	reverse_find_place(t_pile **b, int val)
{
	int		pos;
	int		pos_switch;
	t_pile	*pb;

	pb = *b;
	if (!pb || !pb->next || (val > pb->value && val < find_last(*b)))
		return (0);
	pos_switch = 1;
	while (pb->next && pb->value > pb->next->value)
	{
		pos_switch++;
		pb = pb->next;
	}
	if (!pb->next)
		pos_switch = 0;
	pb = *b;
	pos = 1;
	while (pb->next && (val > pb->value || val < pb->next->value))
	{
		pos++;
		pb = pb->next;
	}
	if (!pb->next)
		return (pos_switch);
	return (pos);
}

void	reverse_insert(t_piles *piles, int sep)
{
	t_pile	*pa;
	int		min_pos;
	int		min_val;
	int		to_put;
	int		*to_min_pos;

	pa = piles->pa;
	min_pos = -1;
	to_min_pos = &min_pos;
	min_val = find_closer_mini(piles, pa, to_min_pos, sep);
	to_put = reverse_find_place(&piles->pb, min_val);
	double_switch(piles, min_pos, to_put);
	active_push(piles, 0);
}
