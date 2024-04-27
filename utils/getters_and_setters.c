/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_and_setters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:43:55 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/25 19:55:24 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	return_value;

	pthread_mutex_lock(mutex);
	return_value = *value;
	pthread_mutex_unlock(mutex);
	return (return_value);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	return_value;

	pthread_mutex_lock(mutex);
	return_value = *value;
	pthread_mutex_unlock(mutex);
	return (return_value);
}

bool	simulation_finished(t_data *data)
{
	return (get_bool(&data->data_mutex, &data->end_simulation));
}