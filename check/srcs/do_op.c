#include "checker.h"

int 	handle_swap(t_pile **pa, t_pile **pb, char *temp)
{
	if (temp[1] == 'a' && temp[2] == '\n')
	{
		swap(*pa);
		return (1);
	}
	else if (temp[1] == 'b' && temp[2] == '\n')
	{
		swap(*pb);
		return (1);
	}
	else if (temp[1] == 's' && temp[2] == '\n')
	{	
		swap(*pa);
		swap(*pb);
		return (1);
	}
	return (0);
}

int 	handle_rot(t_pile **pa, t_pile **pb, char *temp)
{
	if (temp[1] == 'a' && temp[2] == '\n')
	{
		rotate(pa);
		return (1);
	}
	else if (temp[1] == 'b' && temp[2] == '\n')
	{
		rotate(pb);
		return (1);
	}
	else if (temp[1] == 'r' && temp[2] == '\n')
	{	
		rotate(pa);
		rotate(pb);
		return (1);
	}
	return (0);
}

int 	handle_rev_rot(t_pile **pa, t_pile **pb, char *temp)
{
	char t[1];

	read(0, t, 1);
	if (t[0] != '\n')
		return (0);
	if (temp[2] == 'a')
	{
		rev_rotate(pa);
		return (1);
	}
	else if (temp[2] == 'b')
	{
		rev_rotate(pb);
		return (1);
	}
	else if (temp[2] == 'r')
	{	
		rev_rotate(pa);
		rev_rotate(pb);
		return (1);
	}
	return (0);
}

int 	handle_push(t_pile **pa, t_pile **pb, char *temp)
{	
	if (temp[1] == 'a' && temp[2] == '\n')
	{
		push(pb, pa);
		return (1);
	}
	else if (temp[1] == 'b' && temp[2] == '\n')
	{
		push(pa, pb);
		return (1);
	}
	else
		return (0);
}

int	do_op(t_pile **pa, t_pile **pb)
{
	char	temp[3];
	int	lu;
	
	while ((lu = read(0, temp, 3)))
	{
		write(2, "\n", 1);
		write(2, temp, lu);
		write(2, "\n", 1);
		if (lu < 3 || (temp[0] != 's' && temp[0] != 'p' && temp[0] != 'r'))
			return (0);
		if (temp[0] == 's' && !(handle_swap(pa, pb, temp)))
			return (0);
		else if (temp[0] == 'p'&& !(handle_push(pa, pb, temp)))
			return (0);
		else if (temp[0] == 'r' && temp[2] == '\n'
				&& !(handle_rot(pa, pb, temp)))
			return (0);
		else if (temp[0] == 'r' && temp[1] == 'r' && temp[2] != '\n' 
				&& !(handle_rev_rot(pa, pb, temp)))
			return (0);
		print_piles(*pa, *pb);
	}
	return (1);
}
