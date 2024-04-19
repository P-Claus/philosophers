/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:59:36 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/19 21:17:20 by pclaus           ###   ########.fr       */
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
	long				time_since_last_meal;
	t_fork				*first_fork;
	t_fork				*second_fork;
	pthread_t			thread_id;
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
	pthread_mutex_t		data_mutex;
	t_fork				*forks;
	t_philosopher		*philosophers;
}						t_data;
/* ERROR CHECKING */
int						check_if_string_is_numeric(char **argv);
int						check_if_string_is_int(char **argv);

/* UTILS */
void					print_error(char *error);
void					print_success(char *message);
int						str_is_numeric(char *str);
long					ft_atoi_long(const char *str);
int						convert_string_to_integer(char *str);

/* SOURCE FILES */
int						parse_input(t_data *data, char **argv);
int						init_data(t_data *data);
void					init_philosophers(t_data *data);
void					start_dinner(t_data *data);

#endif