/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:41:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 16:58:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(t_dinner_config *const config)
{
	t_table *const	table = init_table(config);

	print_config(config);
	start_dinner(table, config);
	clean_table(table);
}
