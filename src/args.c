/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:09:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/12 13:02:25 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	read_args(t_table *table, int argc, char **argv)
{
	table->philo_number = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
	{
		table->nb_to_eat = -1;
		return (0);
	}
	table->nb_to_eat = ft_atoi(argv[5]);
	return (0);
}

int	init_data(t_table *table, int argc, char **argv)
{
	if (read_args(table, argc, argv))
		return (1);
	if (create_mutex(table))
		return (1);
	if (create_threads(table))
		return (1);
	assign_forks(table);
	return (0);
}
