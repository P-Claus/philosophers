/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_is_not_numeric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:23:20 by pclaus            #+#    #+#             */
/*   Updated: 2024/07/18 09:13:01 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	str_is_not_numeric(char *str)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != '\0')
	{
		if ((str[count] >= '0' && str[count] <= '9') || str[count] == ' ')
			count++;
		else
			return (1);
	}
	return (0);
}

int	argv_is_not_numeric(char **argv)
{
	int	iter;

	iter = 1;
	while (argv[iter])
	{
		if (str_is_not_numeric(argv[iter]))
		{
			print_error("Please enter unsigned integers as arguments\n");
			return (1);
		}
		iter++;
	}
	return (0);
}
