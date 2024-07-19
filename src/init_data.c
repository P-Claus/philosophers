/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:21:22 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/19 15:22:17 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	allocate_memory(t_data *data)
{
	data->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->nb_of_philosophers);
	if (!data->philosophers)
		return (1);
	data->forks = (t_fork *)(malloc(sizeof(t_fork) * data->nb_of_philosophers));
	if (!data->forks)
	{
		free(data->philosophers);
		return (1);
	}
	return (0);
}

int	init_data(t_data *data, int iter)
{
	data->end_simulation = false;
	data->all_threads_ready = false;
	data->nb_of_threads_running = 0;
	if (allocate_memory(data))
		return (1);
	if (pthread_mutex_init(&data->data_mutex, NULL))
	{
		free(data->philosophers);
		free(data->forks);
		print_error("Failed to create a mutex\n");
		return (1);
	}
	while (++iter < data->nb_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[iter].fork, NULL))
		{
			mutex_forks_error("Failed to create a mutex\n", data, iter);
			return (1);
		}
		data->forks[iter].fork_id = iter;
	}
	if (init_philosophers(data))
		return (1);
	return (0);
}
