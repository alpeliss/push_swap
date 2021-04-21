#include "pile.h"

void	triple_tri(t_piles *piles);
void	active_push(t_piles *piles, int dir);
void	active_rotate(t_pile **a, int dir);
void	active_rev_rotate(t_pile **a, int dir);
void	insert(t_piles *piles);
int	check_order(t_pile **a);
int	find_last(t_pile *pa);
void	reverse_insert(t_piles *piles);