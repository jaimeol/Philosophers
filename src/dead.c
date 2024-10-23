/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:52:01 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/01 16:55:35 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->internal_mutex);
	if (get_moment() - philo->last_meal >= philo->table->time_to_die)
	{
		philo->dead = 1;
		pthread_mutex_unlock(&philo->internal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->internal_mutex);
	return (0);
}

int	dead_control(t_table *table, int i)
{
	int	dead;

	i = 0;
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
	return (end);
}

void	set_end(t_table *table)
{
	pthread_mutex_lock(&table->monitor_mutex);
	table->end = 1;
	pthread_mutex_unlock(&table->monitor_mutex);
}

int	all_meals_done(int meals, t_table *table)
{
	return (meals == table->philo_number);
}
