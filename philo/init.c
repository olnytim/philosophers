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
}

static void	ft_philo_init(t_table *table)
{
	unsigned int	i;

	table->thread = malloc(sizeof(t_philo) * table->philos);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philos);
	i = 0;
	while (i < table->philos)
		pthread_mutex_init(table->forks + i++, 0);
	i = 0;
	while (i < table->philos)
	{
		table->thread[i].id = i + 1;
		// printf("philo[%u]: %u\n", i, table->thread[i].id);
		table->thread[i].times_ate = 0;
		table->thread[i].fork1 = &table->forks[i];
		// printf("fork1[%u]: %p\n", i, table->thread[i].fork1);
		if (i != table->philos - 1)
			table->thread[i].fork2 = &table->forks[i + 1];
		else
			table->thread[i].fork2 = &table->forks[0];
		// printf("fork2[%u]: %p\n", i, table->thread[i].fork2);
		++i;
	}
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
	ft_philo_init(table);
	ft_print(table);
	return (table);
}