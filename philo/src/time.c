/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   time.c                                             |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/08/04 19:18:59 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/08/04 19:19:00 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	ft_currect_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - ft_start_time());
}

time_t	ft_start_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_sleep(time_t sleep_time)
{
	time_t	awake;

	awake = ft_start_time() + sleep_time;
	while (ft_start_time() < awake)
		usleep(10);
}
