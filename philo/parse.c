/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgalyaut <tgalyaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:53:26 by olnytim           #+#    #+#             */
/*   Updated: 2023/08/04 16:06:06 by tgalyaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
			return (1);
		num = ft_atoi(av[i]);
		if (i == 1 && num <= 0)
			return (1);
		if (i != 1 && num == -1)
			return (1);
		++i;
	}
	return (0);
}