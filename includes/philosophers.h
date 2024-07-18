/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:59:36 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 09:21:20 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*  HEADERS*/
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* COLORS */
# define RESET "\033[0m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"

/* STRUCTURES */
typedef struct s_data	t_data;
typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					fork_id;
}						t_fork;

typedef struct s_philosopher
{
	int					id;
	long				nb_of_meals;
	bool				is_full;
	long				time_of_last_meal;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
	pthread_mutex_t		philosopher_mutex;
	t_data				*data;
}						t_philosopher;

typedef struct s_data
{
	long				nb_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				max_amount_of_meals;
	long				start_simulation;
	bool				end_simulation;
	bool				all_threads_ready;
	long				nb_of_threads_running;
	pthread_t			monitor;
	pthread_mutex_t		data_mutex;
	pthread_mutex_t		write_mutex;
	t_fork				*forks;
	t_philosopher		*philosophers;
}						t_data;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_time_code;

typedef enum s_philosopher_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
}						t_philosopher_status;

/* ERROR CHECKING */
int						argv_is_not_numeric(char **argv);
int						argv_is_not_int(char **argv);

/* UTILS */
void					print_error(char *error);
int						str_is_numeric(char *str);
long					ft_atoi_long(const char *str);
void					wait_for_all_threads(t_data *data);
long					get_time(t_time_code time_code);
void					ft_usleep(long usec, t_data *data);
void					write_status(t_philosopher_status status,
							t_philosopher *philosopher);
void					increase_amount_of_threads(pthread_mutex_t *mutex,
							long *value);
bool					all_threads_running(pthread_mutex_t *mutex,
							long *nb_of_threads,
							long nb_of_philosophers);
void					cleanup(t_data *data);
void					desynchronise_philosophers(t_philosopher *philosopher);

/* SOURCE FILES */
int						parse_input(t_data *data, char **argv);
int						init_data(t_data *data);
void					init_philosophers(t_data *data);
void					start_dinner(t_data *data);
void					*monitor_dinner(void *table);
void					think_philosopher(t_philosopher *philosopher,
							bool first_function_call);

/* GETTERS AND SETTERS */

void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);
bool					simulation_finished(t_data *data);

#endif
