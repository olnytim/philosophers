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

#include "philo.h"

void	*ft_philo(void *info)
{
	t_philo	*philo;

	philo = (t_philo *)info;
	if (philo->table->must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->table->mutex_init);
	philo->last_meal = ft_currect_time();
	pthread_mutex_unlock(&philo->table->mutex_init);
}