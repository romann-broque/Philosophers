/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:41:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/08 07:54:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_dinner_config *const config)
{
	t_table	*table;

	if (PRINT_DEBUG == true)
		print_config(config);
	if (config->nb_dinner > 0)
	{
		table = init_table(config);
		start_dinner(table, config);
		clean_table(table);
	}
}
