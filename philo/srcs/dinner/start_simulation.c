/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 14:41:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/11 18:08:21 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_retval	start_simulation(t_dinner_config *const config)
{
	t_retval	retval;
	t_table		*table;

	retval = EXIT_FAILURE;
	if (PRINT_DEBUG == true)
		print_config(config);
	if (config->nb_dinner > 0)
	{
		table = init_table(config);
		if (table != NULL)
			retval = start_dinner(table, config);
		clean_table(table);
	}
	return (retval);
}
