/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:05:56 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/08/04 16:59:16 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_print(t_table *table)
{
	printf("philos: %d\n", table->philos);
	printf("time_to_die: %ld\n", table->time_to_die);
	printf("time_to_eat: %ld\n", table->time_to_eat);
	printf("time_to_sleep: %ld\n", table->time_to_sleep);
	printf("must_eat: %d\n", table->must_eat);
	printf("start_time: %ld\n", table->start_time);
}

static pthread_mutex_t	*ft_forks_init(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->philos);
	if (!forks)
		return (error_init2(0, "Malloc error", NULL));
	i = 0;
	while (i < table->philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_init2(0, "Mutex error", NULL));
		++i;
	}
	return (forks);
}

static t_philo	*ft_philo_init(t_table *table)
{
	t_philo			*thread;
	unsigned int	i;

	thread = malloc(sizeof(t_philo) * table->philos);
	if (!thread)
		return (error_init2(0, "Malloc error", NULL));
	table->forks = ft_forks_init(table);
	i = 0;
	while (i < table->philos)
	{
		thread[i].id = i + 1;
		printf("philos[%d]_id: %d\n", i, thread[i].id);
		thread[i].times_ate = 0;
		thread[i].fork1 = &table->forks[i];
		printf("fork1[%d]: %p\n", i, thread[i].fork1);
		if (i != table->philos - 1)
			thread[i].fork2 = &table->forks[i + 1];
		else
			thread[i].fork2 = &table->forks[0];
		printf("fork2[%d]: %p\n", i, thread[i].fork2);
		++i;
	}
	return (thread);
}

t_table	*set_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->philos = ft_atoi(av[i++]);
	table->time_to_die = ft_atoi(av[i++]);
	table->time_to_eat = ft_atoi(av[i++]);
	table->time_to_sleep = ft_atoi(av[i++]);
	table->must_eat = -42;
	if (ac - 1 == 5)
		table->must_eat = ft_atoi(av[i]);
	table->thread = ft_philo_init(table);
	if (!table->thread)
		return (NULL);
	table->start_time = ft_start_time();
	ft_print(table);
	return (table);
}
