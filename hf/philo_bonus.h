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
#define PHILO_BONUS_H

# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/time.h>
# include <stdbool.h>

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