/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:52:01 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/06 17:42:30 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	dead(t_philo *philo)
{
	if (get_moment() - philo->last_meal > philo->table->time_to_die)
	{
		pthread_mutex_lock(&philo->internal_mutex);
		philo->dead = 1;
		pthread_mutex_unlock(&philo->internal_mutex);
		print_action(philo, DEAD);
		return (1);
	}
	return (0);
}

int	dead_control(t_table *table, int i)
{
	pthread_mutex_lock(&table->philos[i].internal_mutex);
	if (table->philos[i].dead)
		return (1);
	pthread_mutex_unlock(&table->philos[i].internal_mutex);
	return (0);
}