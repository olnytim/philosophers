/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:27:37 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/07/28 20:27:38 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/time.h>
# include <stdbool.h>

typedef struct	s_table
{
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	unsigned int	philos;
}				t_table;


typedef struct	s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	times_ate;
	unsigned int	fork[2];
	pthread_mutex_t	meal_time_lock;
	time_t			last_meal;
}				t_philo;

typedef struct	s_condition
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	FORK_1 = 4,
	FORK_2 = 5
}				t_condition;

#endif