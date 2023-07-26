/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:41:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 12:54:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_dinner_config *const config)
{
	t_table	*table;

	print_config(config);
	if (config->nb_dinner > 0)
	{
		table = init_table(config);
		start_dinner(table, config);
		clean_table(table);
	}
}
