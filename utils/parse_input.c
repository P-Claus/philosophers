/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:06:54 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/17 21:35:55 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	parse_input(t_data data, char **argv)
{
	(void)data;
	check_if_string_is_numeric(argv);
	check_if_string_is_int(argv);
}
