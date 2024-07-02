/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:06:48 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/02 15:16:21 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_count;
	size_t			last_meal;
	pthread_mutex_t	internal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
} t_philo;

struct s_table
{
	/* Parametres */
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_to_eat;

	/* Array of forks */
	pthread_mutex_t	*forks;	

	/* Reference to simulation flags */
	size_t			start_time;
	int				dead_flag;
	/* Print mutex */
	pthread_mutex_t	print_mutex;

	/* Philosophers and monitor */
	t_philo			*philos;
	pthread_t		monitor;
};

static int	arg_error(void);
int			read_args(t_table *table, int argc, char **argv);



long int	ft_atoi(const char *str);

#endif