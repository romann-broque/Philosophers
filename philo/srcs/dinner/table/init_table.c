/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:15:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/11 18:15:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_table(t_dinner_config *config)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (table != NULL)
	{
		table->forks = init_forks(config->nb_philosopher);
		if (table->forks == NULL)
		{
			free(table);
			table = NULL;
		}
		else
		{
			table->philosophers
				= init_philosophers(table->forks, config->nb_philosopher);
			set_manager(&(table->manager));
		}
	}
	return (table);
}
