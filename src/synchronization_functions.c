/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization_functions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:42:40 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/28 10:51:35 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	wait_for_all_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->all_threads_ready))
		;
}

bool	all_threads_running(pthread_mutex_t *mutex, long *nb_of_threads,
		long nb_of_philosophers)
{
	bool	return_value;

	return_value = false;
	pthread_mutex_lock(mutex);
	if (*nb_of_threads == nb_of_philosophers)
		return_value = true;
	pthread_mutex_unlock(mutex);
	return (return_value);
}

void	increase_amount_of_threads(pthread_mutex_t *mutex, long *value)
{
	pthread_mutex_lock(mutex);
	(*value)++;
	pthread_mutex_unlock(mutex);
}

void	desynchronise_philosophers(t_philosopher *philosopher)
{
	if (philosopher->data->nb_of_philosophers % 2 == 0)
	{
		if (philosopher->id % 2 == 0)
			ft_usleep(30000, philosopher->data);
	}
	else
	{
		if (philosopher->id % 2 != 0)
			think_philosopher(philosopher, true);
	}
}