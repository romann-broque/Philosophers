/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:17:31 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/11 18:11:25 by rbroque          ###   ########.fr       */
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
	else
		config->nb_philosopher = 0;
}

static void	summon_philosophers(t_table *table, t_dinner_config *config)
{
	init_threads(table, config);
}

static void	lock_start(void)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->can_start_locker));
}

static void	unlock_start(void)
{
	t_manager *const		manager = get_manager();
	t_dinner_config *const	config = get_config();

	usleep(START_TIMELAG_UNIT * config->nb_philosopher);
	set_start_dinner_time();
	pthread_mutex_unlock(&(manager->can_start_locker));
}

t_retval	start_dinner(t_table *table, t_dinner_config *config)
{
	init_config(config);
	init_manager(&(table->manager));
	lock_start();
	summon_philosophers(table, config);
	unlock_start();
	if (config->threads != NULL)
		manager_routine(table, config);
	return (EXIT_SUCCESS);
}
