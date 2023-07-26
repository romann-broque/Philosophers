/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:17:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 12:32:52 by rbroque          ###   ########.fr       */
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
			++i;
		}
	}
}

static void	start_threads(t_table *table, const t_dinner_config *config)
{
	set_start_dinner_time();
	manager_routine(table, config);
}

static void	summon_philosophers(t_table *table, t_dinner_config *config)
{
	init_threads(table, config);
	if (config->threads != NULL)
		start_threads(table, config);
}

static void	lock_start(void)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->can_start_locker));
}

static void	unlock_start(void)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_unlock(&(manager->can_start_locker));
}

void	start_dinner(t_table *table, t_dinner_config *config)
{
	get_config(config);
	init_manager(&(table->manager));
	lock_start();
	summon_philosophers(table, config);
	unlock_start();
}
