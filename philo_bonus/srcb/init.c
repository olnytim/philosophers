/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:05:56 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/09/05 20:30:41 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo_bonus.h"

static void	ft_philo_init(t_table *table)
{
	unsigned int	i;

	table->thread = malloc(sizeof(t_philo) * table->philos);
	i = 0;
	while (i < table->philos)
	{
		table->thread[i].id = i + 1;
		table->thread[i].times_ate = 0;
		table->thread[i].table = table;
		table->thread[i].pid = 0;
		++i;
	}
}

static void	ft_destinit_sem(t_table *table)
{
	sem_unlink("forks_sem");
	sem_unlink("output_sem");
	sem_unlink("meal_lock_sem");
	sem_unlink("eat_counter_sem");
	table->forks_sem = sem_open("forks_sem", O_CREAT, 0666, table->philos);
	table->output_sem = sem_open("output_sem", O_CREAT, 0666, 1);
	table->meal_lock_sem = sem_open("meal_lock_sem", O_CREAT, 0666, 1);
	table->eat_counter_sem = sem_open("eat_counter_sem", O_CREAT, 0666, 1);
	if (table->forks_sem == SEM_FAILED
		|| table->output_sem == SEM_FAILED
		|| table->meal_lock_sem == SEM_FAILED
		|| table->eat_counter_sem == SEM_FAILED)
	{
		printf("error with sems\n");
		exit (1);
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
	if (table->time_to_die < 60 || table->time_to_eat < 60
		|| table->time_to_sleep < 60)
		return (NULL);
	table->must_eat = -42;
	if (ac - 1 == 5)
		table->must_eat = ft_atoi(av[i]);
	table->bool_flag = 0;
	table->start_time = ft_start_time();
	ft_destinit_sem(table);
	ft_philo_init(table);
	if (!table->thread)
		return (NULL);
	return (table);
}
