/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_diner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:21:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/01 19:42:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_diner(t_stat *stats)
{
	t_table	table;

	init_table(&table, stats);
	print_stat(stats);
	clean_table(&table);
}
