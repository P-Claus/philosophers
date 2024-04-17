/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:21:22 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/17 19:30:07 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	init_data(t_data *data, char **argv)
{
	data->nb_of_philosophers = atoi(argv[1]);
	// data->time_to_die = argv[2];
	// data->time_to_eat = argv[3];
	// data->time_to_sleep = argv[4];
	// if (argv[5])
	// data->max_amount_of_meals = argv[5];
}