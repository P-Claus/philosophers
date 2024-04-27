/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:36:32 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/27 14:47:29 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	*handle_one_philosopher(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	wait_for_all_threads(philosopher->data);
	set_long(&philosopher->philosopher_mutex,
		&philosopher->time_since_last_meal, get_time(MILLISECOND));
	increase_amount_of_threads(&philosopher->data->data_mutex,
		&philosopher->data->nb_of_threads_running);
	write_status(TAKE_FIRST_FORK, philosopher);
	while (!simulation_finished(philosopher->data))
		usleep(200);
	return (NULL);
}

static void	think_philosopher(t_philosopher *philosopher)
{
	write_status(THINKING, philosopher);
}

static void	eat_philosopher(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->first_fork->fork);
	write_status(TAKE_FIRST_FORK, philosopher);
	pthread_mutex_lock(&philosopher->second_fork->fork);
	write_status(TAKE_SECOND_FORK, philosopher);
	set_long(&philosopher->philosopher_mutex,
		&philosopher->time_since_last_meal, get_time(MILLISECOND));
	philosopher->nb_of_meals++;
	write_status(EATING, philosopher);
	ft_usleep(philosopher->data->time_to_eat, philosopher->data);
	if (philosopher->data->max_amount_of_meals > 0
		&& philosopher->nb_of_meals == philosopher->data->max_amount_of_meals)
		set_bool(&philosopher->philosopher_mutex, &philosopher->is_full, true);
	pthread_mutex_unlock(&philosopher->first_fork->fork);
	pthread_mutex_unlock(&philosopher->second_fork->fork);
}

void	*dinner_simulation(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	wait_for_all_threads(philosopher->data);
	/*set the time of the last meal*/
	set_long(&philosopher->philosopher_mutex,
		&philosopher->time_since_last_meal, get_time(MILLISECOND));
	/*increase the amount to sync with the monitor function*/
	increase_amount_of_threads(&philosopher->data->data_mutex,
		&philosopher->data->nb_of_threads_running);
	while (!simulation_finished(philosopher->data))
	{
		if (philosopher->is_full)
			break ;
		// 2)eat
		eat_philosopher(philosopher);
		// 3)sleep
		write_status(SLEEPING, philosopher);
		ft_usleep(philosopher->data->time_to_sleep, philosopher->data);
		// 4)thinking
		think_philosopher(philosopher);
	}
	return (0);
}

void	start_dinner(t_data *data)
{
	int	iter;

	iter = 0;
	if (data->max_amount_of_meals == 0)
		return ;
	if (data->nb_of_philosophers == 1)
		pthread_create(&data->philosophers[0].thread_id, NULL,
			handle_one_philosopher, &data->philosophers[0]);
	else
	{
		while (iter < data->nb_of_philosophers)
		{
			// printf("nb of philosophers: %ld\n", data->nb_of_philosophers);
			pthread_create(&data->philosophers[iter].thread_id, NULL,
				dinner_simulation, &data->philosophers[iter]);
			iter++;
		}
	}
	pthread_create(&data->monitor, NULL, monitor_dinner, data);
	data->start_simulation = get_time(MILLISECOND);
	set_bool(&data->data_mutex, &data->all_threads_ready, true);
	iter = -1;
	while (++iter < data->nb_of_philosophers)
	{
		pthread_join(data->philosophers[iter].thread_id, NULL);
	}
}
