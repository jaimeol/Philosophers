/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:29:13 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/18 12:26:40 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	unlock_forks(pthread_mutex_t *first, pthread_mutex_t *second)
{
	if (first)
		pthread_mutex_unlock(first);
	if (second)
		pthread_mutex_unlock(second);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (dead(philo))
	{
		unlock_forks(philo->left_fork, philo->right_fork);
		return (1);
	}
	print_action(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	if (dead(philo))
	{
		unlock_forks(philo->left_fork, philo->right_fork);
		return (1);
	}
	print_action(philo, FORK);
	print_action(philo, EATING);
	ft_usleep(philo->table->time_to_eat);
	if (is_dead(philo))
	{
		unlock_forks(philo->left_fork, philo->right_fork);
		return (1);
	}
	philo->last_meal = get_moment();
	increase_eat_count(philo);
	unlock_forks(philo->left_fork, philo->right_fork);
	return (0);
}

void	sleep_action(t_philo *philo)
{
	print_action(philo, SLEEPING);
	ft_usleep(philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_action(philo, THINKING);
}

int	meals_completed(t_philo *philo)
{
	int	meals;

	if (philo->table->nb_to_eat == -1)
		return (0);
	pthread_mutex_lock(&philo->internal_mutex);
	meals = philo->eat_count;
	pthread_mutex_unlock(&philo->internal_mutex);
	return (meals == philo->table->nb_to_eat);
}
