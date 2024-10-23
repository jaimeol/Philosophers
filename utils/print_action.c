/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:39:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/23 13:32:46 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_action(t_philo *philo, t_action action)
{
	size_t	moment;

	moment = get_moment() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (action == EATING && !is_dead(philo))
		printf("%ld %d is eating\n", moment, philo->id);
	else if (action == SLEEPING && !is_dead(philo))
		printf("%ld %d is sleeping\n", moment, philo->id);
	else if (action == THINKING && !is_dead(philo))
		printf("%ld %d is thinking\n", moment, philo->id);
	else if (action == FORK && !is_dead(philo))
		printf("%ld %d has taken a fork\n", moment, philo->id);
	else if (action == DEAD)
		printf("\033[0;31m%ld %d died\033[0m\n", moment, philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
}
