/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:06:58 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/17 15:29:57 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		print_success(argv[1]);
	}
	else
		print_error("This is not how it should be...");
}