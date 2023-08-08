/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   output.c                                           |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/08/06 19:48:13 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/08/06 19:48:14 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, int is_dead, int cases)
{
	pthread_mutex_lock(&philo->table->output_lock);
	if (ft_the_end(philo->table) == 1 && is_dead == 0)
	{
		pthread_mutex_unlock(&philo->table->output_lock);
		return ;
	}
	if (cases == 0)
		printf("%ld %d %s\n", ft_currect_time(), philo->id, "died");
	else if (cases == 1)
		printf("%ld %d %s\n", ft_currect_time(), philo->id, "is sleeping");
	else if (cases == 2)
		printf("%ld %d %s\n", ft_currect_time(), philo->id, "is thinking");
	else if (cases == 3)
		printf("%ld %d %s\n", ft_currect_time(), philo->id, "has taken a fork");
	else if (cases == 4)
		printf("%ld %d %s\n", ft_currect_time(), philo->id, "is eating");
	pthread_mutex_unlock(&philo->table->output_lock);
}
