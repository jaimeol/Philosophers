/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 18:32:53 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/01 12:00:18 by jolivare         ###   ########.fr       */
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
		i++;
	}
	return (0);
}