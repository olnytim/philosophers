/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:04:57 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/08/04 16:06:02 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	ft_go(t_table *table)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < table->philos)
// 	{
// 		if (pthread_create(&table->thread[i].thread, NULL,
// 			&ft_philo, &table->thread[i]) != 0)
// 			return (error_init(ERROR_THREAD, NULL, table));
// 		++i;
// 	}
// 	// if (table->philos > 1)
// 	// {
// 	// 	if (pthread_create())
// 	// }
// }

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
	return (EXIT_SUCCESS);
}
