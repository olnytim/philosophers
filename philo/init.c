#include "../hf/philo.h"

t_table	*set_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->philos = parse(av[i++]);
	table->time_to_die = parse(av[i++]);
	table->time_to_eat = parse(av[i++]);
	table->time_to_sleep = parse(av[i++]);
}