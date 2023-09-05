#include "../hf/philo_bonus.h"

static void	ft_forks_init(t_table *table)
{
	unsigned int	i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos);
	if (!table->forks)
		return ;
	i = 0;
	while (i < table->philos)
	{
		if (pthread_mutex_init(&table->forks[i], 0))
			return ;
		++i;
	}
}

static void	ft_philo_init(t_table *table)
{
	unsigned int	i;

	table->thread = malloc(sizeof(t_philo) * table->philos);
	ft_forks_init(table);
	i = 0;
	while (i < table->philos)
	{
		table->thread[i].id = i + 1;
		table->thread[i].times_ate = 0;
		table->thread[i].fork1 = &table->forks[i];
		if (i != table->philos - 1)
			table->thread[i].fork2 = &table->forks[i + 1];
		else
			table->thread[i].fork2 = &table->forks[0];
		table->thread[i].table = table;
		pthread_mutex_init(&table->thread[i].meal_lock, 0);
		++i;
	}
}

t_table	*set_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philos = ft_atoi(av[i++]);
	table->time_to_die = ft_atoi(av[i++]);
	table->time_to_eat = ft_atoi(av[i++]);
	table->time_to_sleep = ft_atoi(av[i++]);
	table->must_eat = -42;
	if (ac - 1 == 5)
		table->must_eat = ft_atoi(av[i]);
	ft_philo_init(table);
	pthread_mutex_init(&table->output_lock, 0);
	pthread_mutex_init(&table->end_lock, 0);
	table->bool_flag = 0;
	if (!table->thread)
		return (NULL);
	return (table);
}
