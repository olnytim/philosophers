/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 20:27:25 by tgalyaut          #+#    #+#             */
/*   Updated: 2023/07/28 20:27:26 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hf/philo_bonus.h"

static int	ft_isnum(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		++str;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	unsigned long long int	num;
	int						i;

	i = 0;
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	if (num > INT_MAX)
		return (-1);
	return (num);
}

int	ft_parse(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		if (ft_isnum(av[i]))
			return (ft_out(ERROR_INPUT, av[i], EXIT_FAILURE));
		num = ft_atoi(av[i]);
		if (i == 1 && num <= 0)
			return (ft_out(ERROR_PINPUT, 0, EXIT_FAILURE));
		if (i != 1 && num == -1)
			return (ft_out(ERROR_INPUT, av[i], EXIT_FAILURE));
		++i;
	}
	return (0);
}
