/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:20:10 by olnytim           #+#    #+#             */
/*   Updated: 2023/09/05 20:14:06 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <fcntl.h>

# define PROG_NAME "philo:"
# define ERROR_USAGE "%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philos_must_eat]\n"
# define ERROR_INPUT "%s invalid input: %s: \
use available unsigned integer\n"
# define ERROR_PINPUT "%s ivalid input: \
use available amount of philos\n"
# define ERROR_THREAD "%s error: thread not created\n"
# define ERROR_INIT "%s error: wrong params. Use each param > 59\n"
# define ERROR_MALLOC "%s error: memory not allocated\n"
# define ERROR_MUTEX "%s error: mutex not created\n"

typedef struct s_philo
{
	int				id;
	int				pid;
	unsigned int	times_ate;
	time_t			last_meal;
	pthread_t		checker;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	unsigned int	philos;
	unsigned int	must_eat;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			last_meal;
	time_t			start_time;
	pthread_t		eat_check;
	pthread_t		die_check;
	sem_t			*eat_counter_sem;
	sem_t			*forks_sem;
	sem_t			*output_sem;
	sem_t			*end_lock_sem;
	sem_t			*meal_lock_sem;
	struct s_philo	*thread;
	int				bool_flag;
}	t_table;

/* parsing functions */
int		ft_parse(int ac, char **av);
int		ft_atoi(char *str);

/* errors functions */
int		ft_out(char	*str, char *reas, int ret);
int		error_init(char *str, char *reas);

t_table	*set_table(int ac, char **av, int i);

/* work with time */
void	ft_delay(time_t start_time);
void	ft_sleep(time_t sleep_time);
time_t	ft_start_time(void);
time_t	ft_current_time(t_philo *philo);

/* thread init */
void	ft_philo(t_philo *philo);

/* you are dead */
void	ft_execution(t_table *table);
void	*ft_philo_is_dead(void *info);

/* to norm code */
int		ft_check(t_table *table, unsigned int *i, int *flag);

#endif
