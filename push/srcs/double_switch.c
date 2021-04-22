#include "push_swap.h"

static int	find_min(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (0);
	else if (b <= a && b <= c && b <= d)
		return (1);
	else if (c <= a && c <= b && c <= d)
		return (2);
	else
		return (3);
}

void	handle_mov(t_piles *piles, int mov_a, int mov_b, int order)
{
	if (order)
	{
		while (mov_a)
		{
			active_rotate(&piles->pa, 0);
			mov_a--;
		}
		while (mov_b)
		{
			active_rev_rotate(&piles->pb, 1);
			mov_b--;
		}
		return ;
	}
	while (mov_a)
	{
		active_rev_rotate(&piles->pa, 0);
		mov_a--;
	}
	while (mov_b)
	{
		active_rotate(&piles->pb, 1);
		mov_b--;
	}
}

static void	double_rotate(t_piles *piles, int mov_a, int mov_b)
{
	while (mov_a && mov_b)
	{
		write(1, "rr\n", 3);
		rotate(&piles->pa);
		rotate(&piles->pb);
		mov_a--;
		mov_b--;
	}
	while (mov_a)
	{
		active_rotate(&piles->pa, 0);
		mov_a--;
	}
	while (mov_b)
	{
		active_rotate(&piles->pb, 1);
		mov_b--;
	}
}

static void	double_rev_rotate(t_piles *piles, int mov_a, int mov_b)
{
	while (mov_a && mov_b)
	{
		write(1, "rrr\n", 4);
		rev_rotate(&piles->pa);
		rev_rotate(&piles->pb);
		mov_a--;
		mov_b--;
	}
	while (mov_a)
	{
		active_rev_rotate(&piles->pa, 0);
		mov_a--;
	}
	while (mov_b)
	{
		active_rev_rotate(&piles->pb, 1);
		mov_b--;
	}
}

void	double_switch(t_piles *piles, int pos_a, int pos_b)
{
	int	cas[4];
	int	rev_a;
	int	rev_b;
	int	good_case;

	rev_a = (piles->size_pa - pos_a);
	rev_b = (piles->size_pb - pos_b);
	cas[0] = pos_b;
	if (pos_a > pos_b)
		cas[0] = pos_a;
	cas[1] = rev_b;
	if (rev_a > rev_b)
		cas[1] = rev_a;
	cas[2] = rev_a + pos_b;
	cas[3] = pos_a + rev_b;
	good_case = find_min(cas[0], cas[1], cas[2], cas[3]);
	if (good_case == 0)
		double_rotate(piles, pos_a, pos_b);
	else if (good_case == 1)
		double_rev_rotate(piles, rev_a, rev_b);
	else if (good_case == 2)
		handle_mov(piles, rev_a, pos_b, 0);
	else
		handle_mov(piles, pos_a, rev_b, 1);
}		
