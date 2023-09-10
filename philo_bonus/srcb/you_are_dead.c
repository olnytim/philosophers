/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   you_are_dead.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:08:59 by olnytim           #+#    #+#             */
/*   Updated: 2023/09/05 20:31:44 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo_bonus.h"

void	ft_execution(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->philos)
		kill(table->thread[i++].pid, SIGKILL);
	sem_unlink("forks_sem");
	sem_unlink("output_sem");
	sem_unlink("meal_lock_sem");
	sem_unlink("eat_counter_sem");
	sem_post(table->output_sem);
}

void	ft_eat_checker(t_philo *philo)
{
	if (philo->table->must_eat > 0)
	{
		sem_wait(philo->table->eat_counter_sem);
		if (philo->times_ate >= philo->table->must_eat)
		{
			sem_post(philo->table->eat_counter_sem);
			exit(0);
		}
		else
			sem_post(philo->table->eat_counter_sem);
	}
}

void	*ft_philo_is_dead(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	while (1)
	{
		ft_eat_checker(philo);
		sem_wait(philo->table->meal_lock_sem);
		if (philo->table->time_to_die < (ft_current_time(philo)
				- philo->last_meal))
		{
			sem_wait(philo->table->output_sem);
			printf("%ld %d died\n", ft_current_time(philo), philo->id);
			sem_post(philo->table->meal_lock_sem);
			exit(1);
		}
		else
			sem_post(philo->table->meal_lock_sem);
	}
}
