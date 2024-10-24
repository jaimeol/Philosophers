/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:06:19 by jolivare          #+#    #+#             */
/*   Updated: 2024/09/19 17:17:19 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	arg_error(void)
{
	printf("Incorrect usage.\nExample: ./Philosophers [philo number] ");
	printf("[time to die] [time to eat] [time to sleep] ");
	printf("[number of times philo must eat]\n");
	printf("\033[0;31mLast Parameter is optional\033[0m\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (arg_error());
	if (init_data(&table, argc, argv))
		return (1);
	if (init_threads(&table))
		return (1);
	wait_threads(&table);
	free_data(&table);
	return (0);
}
