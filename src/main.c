/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:58 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/18 21:21:45 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		// init_data(&data, argv);
		parse_input(&data, argv);
		printf("Number of philosophers: %ld\n", data.nb_of_philosophers);
		printf("Time to die: %ld\n", data.time_to_die);
		printf("Time to eat: %ld\n", data.time_to_eat);
		printf("Time to sleep: %ld\n", data.time_to_sleep);
		printf("Max amount of meals: %ld\n", data.max_amount_of_meals);
		print_success("Huzzah");
	}
	else
	{
		print_error("FORMAT ERROR");
	}
}
