/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:30 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/19 21:07:12 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

/*
static void	assign_forks(t_philosopher *philosopher, t_fork *forks,
		int position_of_philosopher)
{
	if (philosopher->id % 2 == 0)
	{
		philosopher->first_fork = &forks[position_of_philosopher];
		philosopher->second_fork = &forks[(position_of_philosopher + 1)
			% philosopher->data->nb_of_philosophers];
	}
	if (philosopher->id % 2 != 0)
	{
		philosopher->first_fork = &forks[(position_of_philosopher
				+ 1) & philosopher->data->nb_of_philosophers];
		philosopher->second_fork = &forks[position_of_philosopher];
	}
}
*/

void	init_philosophers(t_data *data)
{
	int				iter;
	t_philosopher	*philosopher;

	iter = 0;
	while (iter++ < data->nb_of_philosophers)
	{
		philosopher = data->philosophers + iter;
		philosopher->id = iter + 1;
		philosopher->is_full = false;
		philosopher->nb_of_meals = 0;
		philosopher->data = data;
		// assign_forks(philosopher, data->forks, iter);
	}
}
