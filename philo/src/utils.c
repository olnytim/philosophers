/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:21:37 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/09/05 17:29:59 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo.h"

int	ft_check(t_table *table, unsigned int *i, int *flag)
{
	while (*i < table->philos)
	{
		pthread_mutex_lock(&table->thread[*i].meal_lock);
		if (ft_execution(&table->thread[*i]))
			return (1);
		if ((int)table->must_eat != -42)
		{
			if (table->thread[*i].times_ate < table->must_eat)
				*flag = 0;
			else
			{
				ft_set_bool_flag(table, 1);
				pthread_mutex_unlock(&table->thread[*i].meal_lock);
				return (1);
			}
		}
		pthread_mutex_unlock(&table->thread[*i++].meal_lock);
	}
	return (0);
}
