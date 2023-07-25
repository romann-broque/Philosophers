/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:17:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 15:50:37 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_threads(
	t_table *table,
	t_dinner_config *config
	)
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
			pthread_detach(config->threads[i]);
			++i;
		}
	}
}

static void	start_threads(t_table *table, const t_dinner_config *config)
{
	t_manager *const	manager = &(table->manager);

	pthread_mutex_lock(&(manager->action_locker));
	pthread_mutex_lock(&(manager->speak_locker));
	manager->start_dinner_time = get_time();
	manager->can_dinner_start = true;
	pthread_mutex_unlock(&(manager->speak_locker));
	pthread_mutex_unlock(&(manager->action_locker));
	manager_routine(table, config);
}

void	start_dinner(t_table *table, t_dinner_config *config)
{
	get_config(config);
	init_manager(&(table->manager));
	init_threads(table, config);
	if (config->threads != NULL)
		start_threads(table, config);
}
