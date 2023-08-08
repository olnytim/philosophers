/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   philo.c                                            |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/08/06 18:12:26 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/08/06 18:12:27 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"\

static void	*ft_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	ft_print_status(philo, 0, 3);
	ft_sleep(philo->table->time_to_die);
	ft_print_status(philo, 0, 0);
	pthread_mutex_unlock(philo->fork1);
	return (NULL);
}

void	*ft_philo(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	if (philo->table->must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = ft_currect_time();
	pthread_mutex_unlock(&philo->meal_lock);
	if (philo->table->time_to_die == 0)
		return (NULL);
	if (philo->table->philos == 1)
		return (ft_one_philo(philo));
	return (NULL);
}
