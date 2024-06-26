/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_string_is_numeric.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:23:20 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/19 18:03:53 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

int	check_if_string_is_numeric(char **argv)
{
	int	iter;

	iter = 1;
	while (argv[iter])
	{
		if (str_is_numeric(argv[iter]) != 1)
		{
			print_error("One of the arguments is not a positive integer");
			return (1);
		}
		iter++;
	}
	return (0);
}

int	str_is_numeric(char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '\0')
	{
		if ((str[count] >= '0') && (str[count] <= '9'))
			count++;
		else
			return (0);
	}
	return (1);
}
