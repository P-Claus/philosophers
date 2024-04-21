/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:16:07 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/21 15:45:37 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	write_status(t_philosopher_status status, t_philosopher *philosopher)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philosopher->data->start_simulation;
	if (philosopher->is_full)
		return ;
	pthread_mutex_lock(&philosopher->data->write_mutex);
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK)
		&& !philosopher->data->end_simulation)
		printf(YELLOW "%-6ld" RESET " %d has taken a fork\n", elapsed,
			philosopher->id);
	else if (status == EATING && !philosopher->data->end_simulation)
		printf(YELLOW "&-6ld %d is eating\n" RESET, elapsed, philosopher->id);
	else if (status == SLEEPING && !philosopher->data->end_simulation)
		printf(YELLOW "%-6ld" RESET " %d is sleeping\n", elapsed,
			philosopher->id);
	else if (status == THINKING && !philosopher->data->end_simulation)
		printf(YELLOW "%-6ld" RESET " %d is thinking\n", elapsed,
			philosopher->id);
	else if (status == DIED)
		printf(RED "%-6ld %d died\n" RESET, elapsed, philosopher->id);
	pthread_mutex_unlock(&philosopher->data->write_mutex);
}
