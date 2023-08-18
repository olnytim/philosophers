/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:18:59 by olnytim           #+#    #+#             */
/*   Updated: 2023/08/12 18:57:18 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo.h"

time_t	ft_current_time(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - philo->table->start_time);
}

time_t	ft_start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(t_table *table, time_t sleep_time)
{
	time_t	awake;

	awake = ft_start_time() + sleep_time;
	while (ft_start_time() < awake)
	{
		if (ft_the_end(table))
			break;
		usleep(10);
	}
}

void	sim_start_delay(time_t start_time)
{
	while (ft_start_time() < start_time)
		continue ;
}