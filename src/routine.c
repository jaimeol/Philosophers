/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:34:00 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/17 16:22:57 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*only_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_moment();
	pthread_mutex_unlock(&philo->internal_mutex);
	print_action(philo, FORK);
	while (!dead(philo))
		usleep(100);
	return (NULL);
}

void	*normal_action(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->internal_mutex);
	philo->last_meal = get_moment();
	pthread_mutex_unlock(&philo->internal_mutex);
	ft_usleep(wait_min(philo));
	while (!is_dead(philo) && !dead(philo))
	{
		if(eat(philo))
			break ;
		if (meals_completed(philo) || dead(philo))
			break ;
		print_action(philo, SLEEPING);
		ft_usleep(philo->table->time_to_sleep);
		if(is_dead(philo) || dead(philo))
			break ;
		think(philo);
	}
	return (NULL);
}

void	*monitor_action(void *arg)
{
	t_table	*table;
	int		i;
	int		flag;
	int		satisfied;

	flag = 1;
	table = (t_table *)arg;
	while (flag)
	{
		i = 0;
		satisfied = 0;
		while (flag && i < table->philo_number)
		{
			satisfied += meals_completed(&table->philos[i]);
			if (dead_control(table, i))
			{
				print_action(&table->philos[i], DEAD);
				set_end(table);
				flag = 0;
			}
			i++;
		}
		if (all_meals_done(satisfied, table))
			break ;
	}
	return (NULL);
}
