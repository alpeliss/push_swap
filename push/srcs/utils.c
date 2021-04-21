#include "push_swap.h"

int	check_order(t_pile **a)
{
	int	bad_order;
	t_pile	*pa;

	pa = *a;
	bad_order = 0;
	while (pa && pa->next && bad_order < 2)
	{
		if (pa->value > pa->next->value)
			bad_order++;
		pa = pa->next;
	}
	if (pa->value > ((t_pile *)*a)->value)
			bad_order++;
	if (bad_order >= 2)
		return (0);
	return (1);

}

void	active_push(t_piles *piles, int dir)
{
	if (dir)
	{
		write(1, "pa\n", 3);
		push(&piles->pb, &piles->pa);
		piles->size_pa++;
		piles->size_pb--;
	}
	else
	{
		write(1, "pb\n", 3);
		push(&piles->pa, &piles->pb);
		piles->size_pa--;
		piles->size_pb++;
	}		
}

void	active_rotate(t_pile **a, int dir)
{
	rotate(a);
	if (!dir)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	active_rev_rotate(t_pile **a, int dir)
{
	rev_rotate(a);
	if (!dir)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}
