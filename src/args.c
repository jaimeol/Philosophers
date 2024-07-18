/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:09:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/18 11:42:34 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	read_args(t_table *table, int argc, char **argv)
{
	table->philo_number = ft_atoi(argv[1]);
	if (is_valid_number(argv[1]) || table->philo_number <= 0)
		return (1);
	table->time_to_die = ft_atoi(argv[2]);
	if (is_valid_number(argv[2]) || table->time_to_die <= 0)
		return (1);
	table->time_to_eat = ft_atoi(argv[3]);
	if (is_valid_number(argv[3]) || table->time_to_eat <= 0)
		return (1);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (is_valid_number(argv[4]) || table->time_to_sleep <= 0)
		return (1);
	if (argc == 5)
	{
		table->nb_to_eat = -1;
		return (0);
	}
	table->nb_to_eat = ft_atoi(argv[5]);
	if (is_valid_number(argv[5]) || table->nb_to_eat <= 0)
		return (1);
	return (0);
}

int	init_data(t_table *table, int argc, char **argv)
{
	if (read_args(table, argc, argv))
	{
		printf("Arg format error\n");
		return (1);
	}
	if (create_mutex(table))
	{
		printf("Mutex error\n");
		return (1);
	}
	if (create_threads(table))
	{
		printf("Thread error\n");
		return (1);
	}
	assign_forks(table);
	return (0);
}
