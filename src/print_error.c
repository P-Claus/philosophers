/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:21:20 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 15:26:51 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_error(char *error)
{
	printf(RED "%s\n" RESET, error);
}

void	mutex_forks_error(char *error, t_data *data, int iter)
{
	int	i;

	i = 0;
	print_error(error);
	while (i > 0)
	{
		pthread_mutex_destroy(&data->forks[iter].fork);
		iter--;
	}
}
