/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   philo_bonus.h                                      |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/08/02 23:20:10 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/08/02 23:20:12 by olnytim                /     \       *   */
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

# define PROG_NAME "philo:"
# define ERROR_USAGE "%s usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philos_must_eat]\n"
# define ERROR_INPUT "%s invalid input: %s: \
use available unsigned integer\n"
# define ERROR_PINPUT "%s ivalid input: \
use available amount of philos\n"
# define ERROR_THREAD "%s error: thread not created\n"
# define ERROR_MALLOC "%s error: memory not allocated\n"
# define ERROR_MUTEX "%s error: mutex not created\n"

typedef struct s_philo
{
	int				id;
	int				pid;
	pthread_t		checker;
	time_t			last_meal;
	unsigned int	times_ate;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	unsigned int	philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	unsigned int	must_eat;
	time_t			last_meal;
	pthread_t		eat_check;
	pthread_t		die_check;
	sem_t			*eat_counter_sem;
	sem_t			*forks_sem;
	sem_t			*output_sem;
	sem_t			*end_lock;
	sem_t			*meal_lock_sem;
	struct s_philo	*philo;
	int				bool_flag;
}	t_table;
