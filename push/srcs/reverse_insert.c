#include "push_swap.h"

static int	find_min_val(t_pile *pa)
{
	int	min_val;

	min_val = pa->value;
	while (pa)
	{
		min_val = (pa->value < min_val) ? pa->value : min_val;
		pa = pa->next;
	}
	return (min_val);
}

static int	find_sep(t_piles *piles, t_pile *pa, int place)
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

static	int	find_closer_mini(t_pile *pa, int *min_pos, int sep)
{
	int	pos;
	int	sep;
	int	min_val;

	pos = 0;
	min_val = 0;
	while (pa)
	{
		if (pa->value <= sep
				&& (*min_pos == -1 || min_pos > piles->size_pa - pos))
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
	int 	pos;
	int 	pos_switch;
	t_pile	*pb;

	pb = *b;
	if (!pb || !pb->next)
		return (0);
	pos_switch = 1;
	while (pb->next && pb->value > pb->next->value)
	{
		pos_switch++;
		pb = pb->next;
	}
	pb = *b;
	if (val > pb->value && val < find_last(*b))
		return (0);
	pos = 1;
	while (pb->next->next && (val > pb->value || val < pb->next->value))
	{
		pos++;
		pb = pb->next;
	}
	if (val > pb->value || val < pb->next->value)
		return (pos_switch);
	return (pos);
}

void		reverse_insert(t_piles *piles)
{
	t_pile	*pa;
	int	*min_pos;
	int	min_val;
	int	to_put;

	pa = piles->pa;
	*min_pos = -1;
	min_val = find_closer_mini(pa, min_pos, find_sep(piles, pa, 25);
	to_put = (reverse_find_place(&piles->pb, min_val);
	*min_pos = (min_pos < piles->size_pa / 2)
		? *min_pos: piles->size_pa - min_pos;
	to_put = (min_pos < piles->size_pa / 2)
		? *min_pos: piles->size_pa - min_pos;
}



