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
	pthread_mutex_lock(philo->fork1);
	ft_print_status(philo, 0, 3);
	pthread_mutex_lock(philo->fork2);
	ft_print_status(philo, 0, 3);
	ft_print_status(philo, 0, 4);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = ft_start_time();
	pthread_mutex_unlock(&philo->meal_lock);
	ft_sleep(philo->table, philo->table->time_to_eat);
	if (!ft_the_end(philo->table))
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->times_ate += 1;
		pthread_mutex_unlock(&philo->meal_lock);
	}
	ft_print_status(philo, 0, 1);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	ft_sleep(philo->table, philo->table->time_to_sleep);
}

static void	ft_think(t_philo *philo, int mute)
{
	time_t	time_to_think;

	pthread_mutex_lock(&philo->meal_lock);
	time_to_think = (philo->table->time_to_die
			- (ft_start_time() - philo->last_meal)
			- philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->meal_lock);
	if (time_to_think < 0)
		time_to_think = 0;
	if (time_to_think == 0 && mute == 1)
		time_to_think = 1;
	if (time_to_think > 600)
		time_to_think = 200;
	if (mute == 0)
		ft_print_status(philo, 0, 2);
	ft_sleep(philo->table, time_to_think);
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
	
}
