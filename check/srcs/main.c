#include "checker.h"

int	main(int ac, char **av)
{
	t_pile	*pa;
	t_pile	*pb;

	pb = NULL;
	if (ac < 2)
		return (write(1, "no pile a\n", 10));
	pa = get_pile_a(av[1]);
	if (!pa)
		return (write(1, "Argument incorrect.\n", 20));
	if (!(check_doublons(pa)))
		return (write(1, "Doublon dans la liste.\n", 23));
	if (!(do_op(&pa, &pb)))
	{
		free_pile(pa);
		free_pile(pb);
		return (write(1, "Operation incorrect.\n", 21));
	}
	if (check_tri(pa, pb))
		write(1, "OK\n", 3);
}
