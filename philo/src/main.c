/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:04:57 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/08/18 20:04:42 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo.h"

static int	ft_go(t_table *table)
{
	unsigned int	i;

	i = 0;
	// table->start_time = ft_start_time();
	table->start_time = ft_start_time() + (table->philos * 20);
	while (i < table->philos)
	{
		if (pthread_create(&table->thread[i].thread, NULL,
				&ft_philo, &table->thread[i]))
			return (error_init(table, ERROR_THREAD, NULL));
		++i;
	}
	if (table->philos > 1)
	{
		if (pthread_create(&table->wasted, NULL,
				&ft_philo_is_dead, table))
			return (error_init(table, ERROR_THREAD, NULL));
	}
	return (1);
}

static void	ft_end(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->philos)
		pthread_join(table->thread[i++].thread, NULL);
	if (table->philos > 1)
		pthread_join(table->wasted, NULL);
	mutexes_end(table);
	// free_table(table);
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac < 5 || ac > 6)
		return (ft_out(ERROR_USAGE, NULL, EXIT_FAILURE));
	if (ft_parse(ac, av))
		return (EXIT_FAILURE);
	table = set_table(ac, av, 1);
	if (!table)
		return (EXIT_FAILURE);
	if(!ft_go(table))
		return (EXIT_FAILURE);
	ft_end(table);
	// system("leaks philo");
	return (EXIT_SUCCESS);
}
