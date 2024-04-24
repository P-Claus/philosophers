/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:36:32 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/24 20:29:48 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

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
	while (philosopher->data->end_simulation == false)
	{
		// 1) if (philosopher->is_full)
		// break ;
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

	iter = -1;
	if (data->max_amount_of_meals == 0)
		return ;
	if (data->nb_of_philosophers == 1)
		; // to do
	else
	{
		while (++iter < data->nb_of_philosophers)
		{
			pthread_create(&data->philosophers[iter].thread_id, NULL,
				dinner_simulation, &data->philosophers[iter]);
		}
		data->start_simulation = get_time(MILLISECOND);
		set_bool(&data->data_mutex, &data->all_threads_ready, true);
	}
	iter = -1;
	while (++iter < data->nb_of_philosophers)
	{
		pthread_join(data->philosophers[iter].thread_id, NULL);
	}
}
