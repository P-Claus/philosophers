/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:06:54 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/16 18:18:28 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

static int	convert_string_to_integer(char *str)
{
	int	iter;
	int	result;

	iter = 0;
	result = 0;
	while (str[iter] && ((str[iter] >= 9 && str[iter] <= 13)
			|| str[iter] == 32))
		iter++;
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
	{
		result = result * 10 + str[iter] - '0';
		iter++;
	}
	return (result);
}

int	parse_input(t_data *data, char **argv)
{
	if (argv_is_not_numeric(argv))
		return (1);
	if (argv_is_not_int(argv))
		return (1);
	data->nb_of_philosophers = convert_string_to_integer(argv[1]);
	data->time_to_die = convert_string_to_integer(argv[2]) * 1000;
	data->time_to_eat = convert_string_to_integer(argv[3]) * 1000;
	data->time_to_sleep = convert_string_to_integer(argv[4]) * 1000;
	if (data->time_to_die < 60000 || data->time_to_eat < 60000
		|| data->time_to_sleep < 60000)
	{
		print_error("Use timestamps that are bigger than 60 ms");
		return (1);
	}
	if (argv[5])
		data->max_amount_of_meals = convert_string_to_integer(argv[5]);
	else
		data->max_amount_of_meals = -1;
	return (0);
}

