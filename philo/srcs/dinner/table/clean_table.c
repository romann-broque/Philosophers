/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 10:43:09 by rbroque          ###   ########.fr       */
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

// static void	clean_manager(t_manager *manager)
// {
// 	pthread_mutex_destroy(&(manager->action_locker));
// 	pthread_mutex_destroy(&(manager->speak_locker));
// }

static void	kill_threads(t_dinner_config *config)
{
	const size_t	nb_threads = config->nb_philosopher;
	size_t			i;

	i = 0;
	while (i < nb_threads)
	{
		pthread_detach(config->threads[i]);
		++i;
	}
}

void	clean_table(t_table *table)
{
	t_dinner_config *const	config = get_config(NULL);

	kill_threads(config);
	clean_forks(table->forks, config->nb_philosopher);
	(void)table;
}
	// clean_manager(&(table->manager));
	// free(table->philosophers);
