/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:36:32 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/21 15:47:23 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	*dinner_simulation(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	wait_for_all_threads(philosopher->data);
	while (philosopher->data->end_simulation == false)
	{
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
			pthread_create(&data->philosophers[iter].thread_id,
				dinner_simulation, &data->philosophers[iter], NULL);
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
