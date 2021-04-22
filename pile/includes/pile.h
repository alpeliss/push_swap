#ifndef PILE_H
# define PILE_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
}			t_pile;

typedef struct s_piles
{
	struct s_pile	*pa;
	struct s_pile	*pb;
	int				size_pa;
	int				size_pb;
}			t_piles;

t_pile		*get_pile_a(char *str);
t_pile		*make_pile(int nb);
t_pile		*ft_atop(char *str, int *i);
t_pile		*free_pile(t_pile *a);
t_pile		*add_back(t_pile *a, t_pile *b);
void		print_piles(t_pile *a, t_pile *b);
int			check_doublons(t_pile *a);
int			check_tri(t_pile *a, t_pile *b);
void		swap(t_pile *a);
void		push(t_pile **from, t_pile **to);
void		rotate(t_pile **a);
void		rev_rotate(t_pile **a);
int			count_pile_size(t_pile *a);

#endif