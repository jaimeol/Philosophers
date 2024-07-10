/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:52:01 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/10 17:18:00 by jolivare         ###   ########.fr       */
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
	int dead;
	pthread_mutex_lock(&table->philos[i].internal_mutex);
	dead = table->philos[i].dead;
	pthread_mutex_unlock(&table->philos[i].internal_mutex);
	return (dead);
}

int	is_dead(t_philo *philo)
{
	int	end;

	pthread_mutex_lock(&philo->table->monitor_mutex);
	end = philo->table->end;
	pthread_mutex_unlock(&philo->table->monitor_mutex);
	if (end)
		return (1);
	return (0);
}

void	set_end(t_table *table)
{
	pthread_mutex_lock(&table->monitor_mutex);
	table->end = 1;
	pthread_mutex_unlock(&table->monitor_mutex);
}

int	all_meals_done(int	meals, t_table *table)
{
	if (table->nb_to_eat == -1)
		return (0);
	if (meals == table->nb_to_eat)
		return (1);
	return (1);
}
