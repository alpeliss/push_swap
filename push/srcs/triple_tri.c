#include "push_swap.h"

static void	cas_un(t_pile **p)
{
	write(1, "sa\nra\n", 6);
	swap(*p);
	rotate(p);
}

static void	cas_deux(t_pile **p)
{
	write(1, "ra\n", 3);
	rotate(p);
}

static void	cas_trois(t_pile **p)
{
	write(1, "sa\nrra\n", 7);
	swap(*p);
	rev_rotate(p);
}

static void	cas_quatre(t_pile **p)
{
	write(1, "rra\n", 4);
	rev_rotate(p);
}

void	triple_tri(t_piles *piles)
{
	int	top;
	int	mid;
	int	bot;

	top = piles->pa->value;
	mid = piles->pa->next->value;
	bot = piles->pa->next->next->value;
	if (top < mid && mid < bot)
		return ;
	if (top < mid && mid > bot && bot > top)
		cas_un(&piles->pa);
	else if (top > mid && mid < bot && bot < top)
		cas_deux(&piles->pa);
	else if (top > mid && mid > bot && bot < top)
		cas_trois(&piles->pa);
	else if (top < mid && mid > bot && bot < top)
		cas_quatre(&piles->pa);
	else
	{
		write(1, "sa\n", 3);
		swap(piles->pa);
	}
}
