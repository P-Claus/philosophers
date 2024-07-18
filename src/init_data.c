/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:21:22 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 09:15:47 by pclaus           ###   ########.fr       */
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
	pthread_mutex_init(&data->data_mutex, NULL);
	pthread_mutex_init(&data->write_mutex, NULL);
	data->forks = (t_fork *)(malloc(sizeof(t_fork) * data->nb_of_philosophers));
	if (!data->forks)
		return (1);
	while (++iter < data->nb_of_philosophers)
	{
		pthread_mutex_init(&data->forks[iter].fork, NULL);
		data->forks[iter].fork_id = iter;
	}
	init_philosophers(data);
	return (0);
}
