/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:21:22 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 15:27:53 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	init_data(t_data *data)
{
	int	iter;

	iter = -1;
	data->end_simulation = false;
	data->all_threads_ready = false;
	data->nb_of_threads_running = 0;
	data->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->nb_of_philosophers);
	if (!data->philosophers)
		return (1);
	if (pthread_mutex_init(&data->data_mutex, NULL))
	{
		free(data->philosophers);
		print_error("Failed to create a mutex\n");
		return (1);
	}
	data->forks = (t_fork *)(malloc(sizeof(t_fork) * data->nb_of_philosophers));
	if (!data->forks)
		return (1);
	while (++iter < data->nb_of_philosophers)
	{
		if (pthread_mutex_init(&data->forks[iter].fork, NULL))
		{	
			mutex_forks_error("Failed to create a mutex\n", data, iter);
			free(data->philosophers);
			free(data->forks);
			return (1);
		}
		data->forks[iter].fork_id = iter;
	}
	if (init_philosophers(data))
		return (1);
	return (0);
}
