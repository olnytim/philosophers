/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:09 by olnytim           #+#    #+#             */
/*   Updated: 2023/08/11 17:47:11 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo.h"

int	ft_out(char	*str, char *reas, int ret)
{
	if (!reas)
		printf(str, "philo:");
	else
		printf(str, "philo:", reas);
	return (ret);
}

void	*free_table(t_table *table)
{
	unsigned int	i;

	if (!table)
		return (NULL);
	if (table->forks != NULL)
		free(table->forks);
	if (table->thread != NULL)
	{
		i = 0;
		while (i < table->philos)
			free(&table->thread[i++]);
		free(table->thread);
	}
	free(table);
	return (NULL);
}

void	mutexes_end(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->thread[i].meal_lock);
		++i;
	}
	pthread_mutex_destroy(&table->output_lock);
	pthread_mutex_destroy(&table->end_lock);
}

int	error_init(t_table *table, char *str, char *reas)
{
	if (table != NULL)
		free_table(table);
	return (ft_out(str, reas, 0));
}
