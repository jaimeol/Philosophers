/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:17:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/18 12:27:28 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	delete_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->forks);
}

void	free_data(t_table *table)
{
	free(table->philos);
	delete_mutex(table);
}

size_t	wait_min(t_philo *philo)
{
	size_t	time;

	time = 0;
	if (philo->id % 2)
	{
		if (philo->table->time_to_eat > philo->table->time_to_die)
			time = philo->table->time_to_die;
		else
			time = philo->table->time_to_eat;
	}
	return (time);
}
