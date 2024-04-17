/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_string_is_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:29:42 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/17 21:57:22 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

int	check_if_string_is_int(char **argv)
{
	int		iter;
	long	nb;

	iter = 1;
	while (argv[iter])
	{
		nb = 0;
		nb = ft_atoi_long(argv[iter]);
		if (nb > INT_MAX)
			print_error("One of the arguments is bigger than MAX_INT");
		iter++;
	}
	return (0);
}

long	ft_atoi_long(const char *str)
{
	long	result;
	int		iter;
	int		sign;

	iter = 0;
	sign = 1;
	result = 0;
	while (str[iter] && ((str[iter] >= 9 && str[iter] <= 13)
			|| str[iter] == 32))
		iter++;
	if (str[iter] == '+' || str[iter] == '-')
	{
		if (str[iter] == '-')
			sign = -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
	{
		result = result * 10 + str[iter] - '0';
		iter++;
	}
	return (result * sign);
}
