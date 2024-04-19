/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_party.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:36:32 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/19 21:13:46 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	*dinner_simulation(void *data)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)data;
	wait_for_all_threads();
	return (0);
}

void	start_dinner(t_data *data)
{
	int iter = 0;
	if (data->max_amount_of_meals == 0)
		return ;
	if (data->nb_of_philosophers == 1)
		; // to do
	else
	{
		while (iter < data->nb_of_philosophers)
		{
			pthread_create(&data->philosophers[iter].thread_id,
				dinner_simulation(data), &data->philosophers[iter], NULL);
		}
	}
}