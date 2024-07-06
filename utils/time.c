/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:08:37 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/04 15:34:30 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/philosophers.h"

size_t	get_time_diff(struct timeval start, struct timeval end)
{
	size_t	start_ms;
	size_t	end_ms;

	start_ms = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	end_ms = (end.tv_sec * 1000) + (start.tv_usec / 1000);
	return (end_ms - start_ms);
}

size_t	get_moment(void)
{
	struct timeval	moment;

	gettimeofday(&moment, NULL);
	return ((moment.tv_sec * 1000) + (moment.tv_usec / 1000)); 
}

void	assign_start(t_table *table)
{
	struct timeval	start;
	
	gettimeofday(&start, NULL);
	table->start_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
}
