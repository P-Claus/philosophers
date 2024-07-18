/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:58 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 09:17:35 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (parse_input(&data, argv) == 1)
			return (1);
		init_data(&data);
		start_dinner(&data);
		cleanup(&data);
	}
	else
		print_error("Please enter the data\
in the correct format\n"
			"The correct format is: ./philosophers\
5 800 200 200 [4]\n");
}
