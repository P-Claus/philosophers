/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:07:07 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/19 16:14:38 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
#include <pthread.h>

void	cleanup(t_data *data)
{
	t_philosopher	*philosopher;
	int				iter;

	iter = 0;
	while (iter < data->nb_of_philosophers)
	{
		philosopher = data->philosophers + iter;
		pthread_mutex_destroy(&philosopher->philosopher_mutex);
		pthread_mutex_destroy(&data->forks[iter].fork);
		iter++;
	}
	pthread_mutex_destroy(&data->data_mutex);
	free(data->forks);
	free(data->philosophers);
}
