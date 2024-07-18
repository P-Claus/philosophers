/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:31:30 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 15:28:18 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	assign_forks(t_philosopher *philosopher, t_fork *forks,
		int position_of_philosopher)
{
	int	philo_nb;

	philo_nb = philosopher->data->nb_of_philosophers;
	philosopher->first_fork = &forks[(position_of_philosopher + 1) % philo_nb];
	philosopher->second_fork = &forks[position_of_philosopher];
	if (philosopher->id % 2 == 0)
	{
		philosopher->first_fork = &forks[position_of_philosopher];
		philosopher->second_fork = &forks[(position_of_philosopher + 1)
			% philo_nb];
	}
}

int	init_philosophers(t_data *data)
{
	int				iter;
	t_philosopher	*philosopher;

	iter = -1;
	while (++iter < data->nb_of_philosophers)
	{
		philosopher = data->philosophers + iter;
		philosopher->id = iter + 1;
		philosopher->is_full = false;
		philosopher->nb_of_meals = 0;
		philosopher->data = data;
		if (pthread_mutex_init(&philosopher->philosopher_mutex, NULL))
		{
			print_error("this is a mutex error\n");
			free(data->forks);
			free(data->philosophers);
			return (1);
		}
		assign_forks(philosopher, data->forks, iter);
	}
	return (0);
}
