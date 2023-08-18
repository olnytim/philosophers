/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:48:13 by olnytim           #+#    #+#             */
/*   Updated: 2023/08/18 19:27:01 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo.h"

void	ft_print_status(t_philo *philo, int is_dead, int cases)
{
	pthread_mutex_lock(&philo->table->output_lock);
	// pthread_mutex_lock(&philo->table->pr);
	// printf("philo is %d cases before %d\n", philo->id, cases);
	// printf("philo is %d is_dead before %d\n", philo->id, is_dead);
	// pthread_mutex_lock(&philo->table->output_lock);
	if (ft_the_end(philo->table) == 1 && is_dead == 0)
	{
		// printf("hi execution\n");
		pthread_mutex_unlock(&philo->table->output_lock);
		// pthread_mutex_unlock(&philo->meal_lock);
		return ;
	}
	// printf("philo is %d cases after %d\n", philo->id, cases);
	// pthread_mutex_unlock(&philo->table->pr);
	if (cases == 0)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "died");
	else if (cases == 1 && philo->table->bool_flag != 1)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "is sleeping");
	else if (cases == 2 && philo->table->bool_flag != 1)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "is thinking");
	else if (cases == 3 && philo->table->bool_flag != 1)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id,
			"has taken a fork");
	else if (cases == 4 && philo->table->bool_flag != 1)
		printf("%ld %d %s\n", ft_current_time(philo), philo->id, "is eating");
	// printf("%d is cases\n", cases);
	pthread_mutex_unlock(&philo->table->output_lock);
	// pthread_mutex_unlock(&philo->meal_lock);
}
