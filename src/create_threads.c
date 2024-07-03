/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:32:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/03 15:56:42 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(table->philo_number * sizeof(t_philo));
	if (!table->philos)
		return (1);
	while (i < table->philo_number)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].eat_count = 0;
		if (pthread_mutex_init(&table->philos[i].internal_mutex, NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->philos[i].internal_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

int	create_mutex(t_table *table)
{
	int	i;
	
	i = 0;
	table->forks = malloc(table->philo_number * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (1);
	while (i < table->philo_number)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	create_mutex_print(t_table *table)
{
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (1);
	return (0);
}

int	init_threads(t_table *table)
{
	int	i;
	
	i = 0;
	while (i < table->philo_number)
	{
		if (table->philo_number == 1)
		{
			if (pthread_create(&table->philos[i].thread, NULL, only_one, table->philos))
				return (1);
		}
		else
		{
			if (pthread_create(&table->philos[i].thread, NULL, normal_action, table->philos))
				return (1);
		}
		i++;
	}
	pthread_create(&table->monitor, NULL, monitor_action, table);
	return (0);
}

void	assign_forks(t_table *table)
{
	int	i;
	int	j;

	i = 0;
	while(i <= table->philo_number)
	{
		j = (i + 1) % table->philo_number;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[j].right_fork = &table->forks[j];
		i++;
	}
	return ;
}