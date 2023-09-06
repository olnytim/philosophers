/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:04:57 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/09/05 20:54:09 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo_bonus.h"

static void	ft_go(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->philos)
	{
		table->thread[i].pid = fork();
		if (table->thread[i].pid < 0)
		{
			printf("error with forks\n");
			exit (1);
		}
		if (table->thread[i].pid == 0)
		{
			pthread_create(&table->thread[i].checker, NULL,
				ft_philo_is_dead, &table->thread[i]);
			ft_philo(&table->thread[i]);
			pthread_join(table->thread[i].checker, NULL);
		}
		++i;
	}
}

int	main(int ac, char **av)
{
	t_table	*table;
	int		pid;

	table = NULL;
	pid = 0;
	if (ac < 5 || ac > 6)
		return (ft_out(ERROR_USAGE, NULL, EXIT_FAILURE));
	if (ft_parse(ac, av))
		return (EXIT_FAILURE);
	table = set_table(ac, av, 1);
	if (!table)
		return (ft_out(ERROR_INIT, NULL, EXIT_FAILURE));
	ft_go(table);
	while (waitpid(-1, &pid, 0) != -1)
	{
		if (pid / 256 == 1)
			ft_execution(table);
	}
	return (EXIT_SUCCESS);
}
