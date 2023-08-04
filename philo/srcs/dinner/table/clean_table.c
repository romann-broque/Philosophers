/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/04 12:26:57 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_forks(pthread_mutex_t *forks, const size_t nb_forks)
{
	size_t	i;

	i = 0;
	while (i < nb_forks)
	{
		pthread_mutex_destroy(forks + i);
		++i;
	}
	free(forks);
}

static void	clean_manager(t_manager *manager)
{
	pthread_mutex_destroy(&(manager->speak_locker));
	pthread_mutex_destroy(&(manager->start_time_locker));
}

static void	wait_for_philosophers(const t_dinner_config *const config)
{
	pthread_t *const	threads = config->threads;
	size_t				i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		pthread_join(threads[i], NULL);
		++i;
	}
}

void	clean_table(t_table *table)
{
	t_dinner_config *const	config = get_config();

	wait_for_philosophers(config);
	clean_forks(table->forks, config->nb_philosopher);
	free(config->threads);
	free(table->philosophers);
	clean_manager(&(table->manager));
	free(table);
}
