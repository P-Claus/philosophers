/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:21:20 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 17:48:27 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_error(char *error)
{
	printf(RED "%s\n" RESET, error);
}

void	mutex_forks_error(char *error, t_data *data, int iter)
{
	print_error(error);
	while (iter >= 0)
	{
		pthread_mutex_destroy(&data->forks[iter].fork);
		iter--;
	}
	free(data->forks);
	free(data->philosophers);
}

void	mutex_philo_error(char *error, t_data *data, int iter)
{
	int	i;

	i = 0;
	print_error(error);
	while (iter >= 0)
	{
		pthread_mutex_destroy(&data->philosophers[iter].philosopher_mutex);
		iter--;
	}
	while (i < data->nb_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i].fork);
		i++;
	}
	free(data->philosophers);
	free(data->forks);
}
