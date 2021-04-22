#include "push_swap.h"

int	find_last(t_pile *pa)
{
	if (!pa)
		return (0);
	while (pa && pa->next)
		pa = pa->next;
	return (pa->value);
}

int	find_place(t_pile **a, int val)
{
	int		pos;
	int		pos_switch;
	t_pile	*pa;

	pa = *a;
	if (!pa || !pa->next)
		return (0);
	pos_switch = 1;
	while (pa->next && pa->value < pa->next->value)
	{
		pos_switch++;
		pa = pa->next;
	}
	pa = *a;
	if (val < pa->value && val > find_last(*a))
		return (0);
	pos = 1;
	while (pa->next->next && (val < pa->value || val > pa->next->value))
	{
		pos++;
		pa = pa->next;
	}
	if (val < pa->value || val > pa->next->value)
		return (pos_switch);
	return (pos);
}

void	insert(t_piles *piles)
{
	int		top_pb;
	int		to_put;
	int		i;

	top_pb = piles->pb->value;
	to_put = find_place(&piles->pa, top_pb);
	i = 0;
	if (to_put < (piles->size_pa + 1) / 2)
	{
		while (i < to_put)
		{
			active_rotate(&piles->pa, 0);
			i++;
		}
	}
	else
	{
		while (i < piles->size_pa - to_put)
		{
			active_rev_rotate(&piles->pa, 0);
			i++;
		}
	}
	active_push(piles, 1);
}
