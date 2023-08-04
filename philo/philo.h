/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:27:37 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/08/04 16:34:20 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	times_ate;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	*meal_time_lock;
	time_t			last_meal;
}	t_philo;

typedef struct s_table
{
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	unsigned int	philos;
	pthread_mutex_t	*forks;
	t_philo			*thread;
}	t_table;

typedef enum e_condition
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	FORK_1 = 4,
	FORK_2 = 5
}	t_condition;

int	ft_parse(int ac, char **av);
int	ft_atoi(char *str);

t_table	*set_table(int ac, char **av, int i);

#endif