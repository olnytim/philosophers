/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:12:26 by olnytim           #+#    #+#             */
/*   Updated: 2023/09/05 20:56:45 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo_bonus.h"

static void	ft_eat(t_philo *philo)
{
	sem_wait(philo->table->forks_sem);
	sem_wait(philo->table->forks_sem);
	sem_wait(philo->table->output_sem);
	printf("%ld %d %s\n", ft_current_time(philo),
		philo->id, "has taken a fork");
	printf("%ld %d %s\n", ft_current_time(philo),
		philo->id, "is eating");
	sem_post(philo->table->output_sem);
	ft_sleep(philo->table->time_to_eat);
	sem_wait(philo->table->meal_lock_sem);
	philo->last_meal = ft_current_time(philo);
	sem_post(philo->table->meal_lock_sem);
	sem_post(philo->table->forks_sem);
	sem_post(philo->table->forks_sem);
	sem_wait(philo->table->eat_counter_sem);
	philo->times_ate += 1;
	sem_post(philo->table->eat_counter_sem);
}

static void	ft_think(t_philo *philo)
{
	sem_wait(philo->table->output_sem);
	printf("%ld %d %s\n", ft_current_time(philo),
		philo->id, "is sleeping");
	sem_post(philo->table->output_sem);
	ft_sleep(philo->table->time_to_sleep);
	sem_wait(philo->table->output_sem);
	printf("%ld %d %s\n", ft_current_time(philo),
		philo->id, "is thinking");
	sem_post(philo->table->output_sem);
}

static void	ft_one_philo(t_philo *philo)
{
	usleep(philo->table->time_to_eat);
	return ;
}

void	ft_philo(t_philo *philo)
{
	sem_wait(philo->table->meal_lock_sem);
	philo->last_meal = ft_current_time(philo);
	sem_post(philo->table->meal_lock_sem);
	if (philo->table->philos == 1)
		ft_one_philo(philo);
	if (philo->id % 2 != 0)
		usleep(philo->table->time_to_sleep);
	while (1)
	{
		ft_eat(philo);
		ft_think(philo);
	}
}
