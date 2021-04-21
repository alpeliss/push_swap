#include "push_swap.h"

static void	back_in_order(t_piles *piles, int pos)
{
	if (pos < piles->size_pa/ 2)
		while (pos + 1)
		{
			active_rotate(&piles->pa, 0);
			pos--;
		}
	else
		while (pos < piles->size_pa - 1)
		{
			active_rev_rotate(&piles->pa, 0);
			pos++;
		}
}

static void	mini_tri(t_piles *piles)
{	
	int	pos;
	t_pile	*pa;

	pos = 0;
	while (piles->size_pa > 3 && !check_order(&piles->pa))
		active_push(piles, 0);
	if (!check_order(&piles->pa))
	{
		write(1, "sa\n", 3);
		swap(piles->pa);
	}
	while (piles->size_pb)
		insert(piles);
	pa = piles->pa;
	while (pa->next && pa->value < pa->next->value)
	{
		pos++;
		pa = pa->next;
	}
	back_in_order(piles, pos);
}

static void	medium_tri(t_piles *piles)
{
	while (!check_order(((t_piles *)piles)->pa))
		reverse_insert(piles);
}

int 		main(int ac, char **av)
{
	t_piles	*piles;

	piles = (t_piles *)malloc(sizeof(t_piles));
	if (ac < 2)
		return (write(1,"no pile a\n", 10));
	piles->pb = NULL;
	if (!(piles->pa = get_pile_a(av[1])))
		return (write(1, "Argument incorrect.\n", 20));
	if (!(check_doublons(piles->pa)))
		return (write(1, "Doublon dans la liste.\n", 23));
	piles->size_pa = count_pile_size(piles->pa);
	piles->size_pb = 0;
	if (check_tri(piles->pa, piles->pb))
		return (0);
	else if (piles->size_pa == 2)
		return (write(1, "ra\n", 3)); 
	else if (piles->size_pa == 3)
		triple_tri(piles);
	else if (piles->size_pa == 45)
		mini_tri(piles);
	else
		medium_tri(piles);
	return (0);
}
