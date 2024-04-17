/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_succes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pclaus <pclaus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:24:59 by pclaus            #+#    #+#             */
/*   Updated: 2024/04/17 15:26:13 by pclaus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopers.h"

void	print_success(char *message)
{
	printf(GREEN "%s\n" RESET, message);
}