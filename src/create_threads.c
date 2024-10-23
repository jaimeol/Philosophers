/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:32:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/10/04 16:12:45 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	table->philos = malloc(table->philo_number * sizeof(t_philo));
	if (!table->philos)
		return (1);
	memset(table->philos, 0, sizeof(t_philo));
	while (i < table->philo_number)
	{
		table->philos[i].id = i + 1;
		table->philos[i].table = table;
		table->philos[i].eat_count = 0;
		table->philos[i].last_meal = get_moment();
		table->end = 0;
		table->philos[i].dead = 0;
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
	pthread_mutex_init(&table->monitor_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	assign_start(table);
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
			if (pthread_create(&table->philos[i].thread, \
				NULL, only_one, table->philos))
				return (1);
		}
		else
		{
			if (pthread_create(&table->philos[i].thread, \
				NULL, normal_action, &table->philos[i]))
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
	while (i < table->philo_number)
	{
		j = (i + 1) % table->philo_number;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[j];
		i++;
	}
	return ;
}

void	wait_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_number)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->monitor, NULL);
}
