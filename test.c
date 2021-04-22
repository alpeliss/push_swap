#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "unistd.h"
#include "math.h"

int main(int	ac, char **av)
{
	int	*tab;
	int	i;
	int	nb_nb;
	int	nb;
	int	nb_random;

	if (ac < 2)
		return (0);
	if (!(nb_random = atoi(av[1])))
		return (0);
	if (!(tab = (int *)malloc(nb_random * sizeof(int))))
		return (0);
	i = 0;
	while (i < nb_random)
	{
		tab[i] = 1;
		i++;
	}
	srandom((unsigned int)time(NULL));
	nb_nb = 0;
	while (nb_nb < nb_random)
	{
		nb = (int)random() % nb_random;
		while (!tab[nb])
			nb = (int)random() % nb_random;
		printf("%d\n", nb);
		tab[nb] = 0;
		nb_nb++;
	}
	free(tab);
	return (0);
}
