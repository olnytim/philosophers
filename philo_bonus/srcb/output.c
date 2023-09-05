/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:48:13 by olnytim           #+#    #+#             */
/*   Updated: 2023/08/18 20:52:31 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo.h"

void	ft_print_status(t_philo *philo, int is_dead, int cases)
{
	pthread_mutex_lock(&philo->table->output_lock);
	if (ft_the_end(philo->table) == 1 && is_dead == 0)
	{
		pthread_mutex_unlock(&philo->table->output_lock);
		return ;
	}
	if (cases == 0)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "died");
	else if (cases == 1)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "is sleeping");
	else if (cases == 2)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "is thinking");
	else if (cases == 3)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id,
			"has taken a fork");
	else if (cases == 4)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "is eating");
	pthread_mutex_unlock(&philo->table->output_lock);
}
