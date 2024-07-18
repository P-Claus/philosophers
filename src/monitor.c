/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:27:50 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 09:18:14 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	philosopher_has_died(t_philosopher *philosopher)
{
	long	time_elapsed;
	long	time_to_die;

	if (get_bool(&philosopher->philosopher_mutex, &philosopher->is_full))
		return (false);
	time_elapsed = get_time(MILLISECOND)
		- get_long(&philosopher->philosopher_mutex,
			&philosopher->time_of_last_meal);
	time_to_die = philosopher->data->time_to_die / 1000;
	if (time_elapsed > time_to_die)
	{
		return (true);
	}
	return (false);
}

void	*monitor_dinner(void *table)
{
	t_data	*data;
	int		iter;

	data = (t_data *)table;
	while (!all_threads_running(&data->data_mutex, &data->nb_of_threads_running,
			data->nb_of_philosophers))
		;
	while (!simulation_finished(data))
	{
		iter = -1;
		while (++iter < data->nb_of_philosophers && !simulation_finished(data))
		{
			if (philosopher_has_died(data->philosophers + iter))
			{
				set_bool(&data->data_mutex, &data->end_simulation, true);
				write_status(DIED, data->philosophers + iter);
			}
		}
	}
	return (NULL);
}
