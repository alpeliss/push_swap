#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "pile.h"

void	triple_tri(t_piles *piles);
void	active_push(t_piles *piles, int dir);
void	active_rotate(t_pile **a, int dir);
void	active_rev_rotate(t_pile **a, int dir);
void	insert(t_piles *piles);
int		check_order(t_pile **a);
int		find_last(t_pile *pa);
void	reverse_insert(t_piles *piles, int sep);
void	double_switch(t_piles *piles, int pos_a, int pos_b);
int		find_sep(t_piles *piles, t_pile *pa, int place);

#endif