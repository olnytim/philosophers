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

/* parsing functions */
int		ft_parse(int ac, char **av);
int		ft_atoi(char *str);

/* errors functions */
int		error_init(t_table *table, char *str, char *reas);
void	*error_init2(t_table *table, char *str, char *reas);
void	*free_table(t_table *table);

t_table	*set_table(int ac, char **av, int i);

/* work with time */
void	ft_sleep(time_t sleep_time);
time_t	ft_start_time(void);
time_t	ft_currect_time(void);

#endif