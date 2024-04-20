/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:58 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/20 15:09:08 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&data, argv) == 1)
			return (1);
		init_data(&data);
		//	start_dinner(&data);
		printf("Number of philosophers: %ld\n", data.nb_of_philosophers);
		printf("Time to die: %ld\n", data.time_to_die);
		printf("Time to eat: %ld\n", data.time_to_eat);
		printf("Time to sleep: %ld\n", data.time_to_sleep);
		printf("Max amount of meals: %ld\n", data.max_amount_of_meals);
		printf("The id of the philosopher is: %d\n", data.philosophers[2].id);
		printf("The first fork of philo 1 is: %d\n",
			data.philosophers[2].first_fork->fork_id);
		printf("The second fork of philo 1 is: %d\n",
			data.philosophers[2].second_fork->fork_id);
		print_success("Huzzah");
	}
	else
	{
		print_error("FORMAT ERROR");
	}
}
