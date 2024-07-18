/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:06:48 by jolivare          #+#    #+#             */
/*   Updated: 2024/07/18 12:30:38 by jolivare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef enum s_action
{
	EATING,
	SLEEPING,
	THINKING,
	FORK,
	DEAD
}	t_action;

typedef struct s_table	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_count;
	int				dead;
	size_t			last_meal;
	pthread_mutex_t	internal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}	t_philo;

struct s_table
{
	int				philo_number;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nb_to_eat;
	pthread_mutex_t	*forks;
	size_t			start_time;
	int				end;
	int				start;	
	pthread_mutex_t	monitor_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	start_mutex;
	t_philo			*philos;
	pthread_t		monitor;
};

int			arg_error(void);
int			read_args(t_table *table, int argc, char **argv);
int			init_data(t_table *table, int argc, char **argv);

int			create_threads(t_table *table);
int			create_mutex(t_table *table);
int			init_threads(t_table *table);
void		assign_forks(t_table *table);
void		wait_threads(t_table *table);
void		wait_start(t_table *table);

void		*only_one(void *arg);
void		*normal_action(void *arg);
void		*monitor_action(void *arg);

size_t		get_moment(void);
size_t		get_time_diff(struct timeval start, struct timeval end);
void		assign_start(t_table *table);
void		ft_usleep(size_t time);
size_t		wait_min(t_philo *philo);
void		print_action(t_philo *philo, t_action action);

int			eat(t_philo *philo);
void		sleep_action(t_philo *philo);
void		think(t_philo *philo);

void		delete_mutex(t_table *table);
void		free_data(t_table *table);

int			dead(t_philo *philo);
int			dead_control(t_table *table, int i);
int			is_dead(t_philo *philo);
void		set_end(t_table *table);
int			meals_completed(t_philo *philo);
int			all_meals_done(int meals, t_table *table);
void		increase_eat_count(t_philo *philo);

int			is_valid_number(char *str);
long int	ft_atoi(const char *str);

#endif