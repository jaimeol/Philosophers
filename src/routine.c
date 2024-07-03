/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:34:00 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/03 17:28:03 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	only_one(t_philo *philo)
{
	
}

int	normal_action(t_philo *philo)
{
	eat();
	sleep();
	think();
}

int	monitor_action(t_philo *philo)
{
	
}
