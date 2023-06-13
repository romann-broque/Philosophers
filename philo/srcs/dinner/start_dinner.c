/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:17:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 23:21:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_threads(t_table *table, t_dinner_config *config)
{
	size_t	i;

	config->threads = (pthread_t *)malloc(
			config->nb_philosopher * sizeof(pthread_t));
	if (config->threads != NULL)
	{
		i = 0;
		while (i < config->nb_philosopher)
		{
			pthread_create(config->threads + i, NULL,
				(void *(*)(void *))philo_routine, table->philosophers + i);
			++i;
		}
	}
}

void	start_dinner(t_table *table, t_dinner_config *config)
{
	init_threads(table, config);
	if (config->threads != NULL)
	{
		table->manager.can_dinner_start = true;
	}
}
