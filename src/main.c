/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:58 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/17 21:22:00 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		// init_data(&data, argv);
		parse_input(data, argv);
		// printf("Number of philosophers: %ld\n", data.nb_of_philosophers);
		print_success("Huzzah");
	}
	else
	{
		print_error("FORMAT ERROR");
	}
}
