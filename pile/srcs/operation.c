#include "pile.h"

void	swap(t_pile *pa)
{
	int	tmp;

	if (!pa || !pa->next)
		return ;
	tmp = pa->value;
	pa->value = pa->next->value;
	pa->next->value = tmp;
}

void	push(t_pile **from, t_pile **to)
{
	t_pile	*tmp;

	if (!from || !(*from))
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

void	rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = (*a);
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;

}
void	rev_rotate(t_pile **a)
{
	t_pile	*tmp;
	t_pile	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	last = (*a);
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *a;
	*a = tmp;
}
