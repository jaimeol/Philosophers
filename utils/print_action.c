/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:39:11 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/10 17:21:52 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philosophers.h"

void	print_action(t_philo *philo, t_action action)
{
	size_t	moment;

	moment = get_moment() - philo->table->start_time;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (action == EATING && !philo->dead)
		printf("%ld %d is eating\n", moment, philo->id);
	else if (action == SLEEPING && !philo->dead)
		printf("%ld %d is sleeping\n", moment, philo->id);
	else if (action == THINKING && !philo->dead)
		printf("%ld %d is thinking\n", moment, philo->id);
	else if (action == FORK && !philo->dead)
		printf("%ld %d has taken a fork\n", moment, philo->id);
	else
		printf("\033[0;31m[%ld] [%d] died\033[0m\n", moment, philo->id);
	pthread_mutex_unlock(&philo->table->print_mutex);
}