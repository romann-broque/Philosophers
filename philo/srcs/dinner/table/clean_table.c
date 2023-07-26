/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:22:55 by rbroque          ###   ########.fr       */
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
	// printf("NB_PHILO: %zu\n", config->nb_philosopher);
	while (i < config->nb_philosopher)
	{
		// printf(YELLOW"philo %zu is waited\n"NC, i);
		pthread_join(threads[i], NULL);
		// printf(GREEN"philo %zu is done\n"NC, i);
		++i;
	}
}

void	clean_table(t_table *table)
{
	t_dinner_config *const	config = get_config(NULL);

	// printf(RED"Start waiting for philos\n"NC);
	wait_for_philosophers(config);
	clean_forks(table->forks, config->nb_philosopher);
	free(config->threads);
	free(table->philosophers);
	clean_manager(&(table->manager));
	free(table);
}
