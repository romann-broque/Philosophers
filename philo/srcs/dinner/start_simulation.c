/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:41:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 10:39:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_dinner_config *config)
{
	t_table	table;

	table = init_table(config);
	print_config(config);
	start_dinner(&table, config);
	clean_table(&table);
}
