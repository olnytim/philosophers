/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:08:09 by olnytim           #+#    #+#             */
/*   Updated: 2023/08/11 17:47:11 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo_bonus.h"

int	ft_out(char	*str, char *reas, int ret)
{
	if (!reas)
		printf(str, "philo:");
	else
		printf(str, "philo:", reas);
	return (ret);
}

int	error_init(char *str, char *reas)
{
	return (ft_out(str, reas, 0));
}
