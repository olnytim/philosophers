/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   you_are_dead.c                                     |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/08/07 16:08:59 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/08/07 16:09:00 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_the_end(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->end_lock);
	if (table->bool_flag == 1)
		i = 1;
	pthread_mutex_unlock(&table->end_lock);
	return (i);
}

static void	ft_set_bool_flag(t_table *table, int flag)
{
	pthread_mutex_lock(&table->end_lock);
	table->bool_flag = flag;
	pthread_mutex_unlock(&table->end_lock);
}

static int	ft_execution(t_philo *philo)
{
	if ((ft_start_time() - philo->last_meal) >= philo->table->time_to_die)
	{
		ft_set_bool_flag(philo->table, 1);
		ft_print_status(philo, 0, 0);
		pthread_mutex_unlock(&philo->meal_lock);
		return (1);
	}
	return (0);
}

static int	ft_finish(t_table *table)
{
	unsigned int	i;
	int				flag;

	i = 0;
	flag = 1;
	while (i < table->philos)
	{
		pthread_mutex_lock(&table->thread[i].meal_lock);
		if (ft_execution(&table->thread[i]))
			return (1);
		if ((int)table->must_eat != -42)
		{
			if (table->thread[i].times_ate < table->must_eat)
				flag = 0;
		}
		pthread_mutex_unlock(&table->thread[i++].meal_lock);
	}
	if ((int)table->must_eat != -42 && flag == 1)
	{
		ft_set_bool_flag(table, 1);
		return (1);
	}
	return (0);
}

void	*ft_philo_is_dead(void *info)
{
	t_table	*table;

	table = (t_table *)info;
	if (table->must_eat == 0)
		return (NULL);
	ft_set_bool_flag(table, 0);
	while (1)
	{
		if (ft_finish(table) == 1)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}