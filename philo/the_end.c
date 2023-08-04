/* ************************************************************************** */
/*                                                                            */
/*                                                    *._           _.*   @   */
/*   the_end.c                                          |\  \\_//  /|     #   */
/*                                                      \/         \/     $   */
/*   By: olnytim <yearagotomorrow@gmail.com>           _|_    V  V  |_    %   */
/*                                                  *=.    =  _*  =   .=* ^   */
/*   Created: 2023/08/04 18:08:09 by olnytim           \= ___________=/   &   */
/*   Updated: 2023/08/04 18:15:00 by olnytim                /     \       *   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_out(char	*str, char *reas, int ret)
{
	if (!reas)
		printf(str, "philo");
	else
		printf(str, "philo", reas);
	return (ret);
}

void	*free_table(t_table *table)
{
	unsigned int	i;

	if (!table)
		return (NULL);
	if (table->forks != NULL)
		free(table->forks);
	if (table->thread != NULL)
	{
		i = 0;
		while (i < table->philos)
			free(&table->thread[i++]);
		free(table->thread);
	}
	free(table);
	return (NULL);
}

int	error_init(t_table *table, char *str, char *reas)
{
	if (table != NULL)
		free_table(table);
	return (ft_out(str, reas, 0));
}

void	*error_init2(t_table *table, char *str, char *reas)
{
	if (table != NULL)
		free_table(table);
	ft_out(str, reas, EXIT_FAILURE);
	return (NULL);
}
