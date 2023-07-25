/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:34:43 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 16:30:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	clean_forks(pthread_mutex_t *forks, const size_t nb_forks)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < nb_forks)
// 	{
// 		pthread_mutex_destroy(forks + i);
// 		++i;
// 	}
// 	free(forks);
// }

// static void	clean_manager(t_manager *manager)
// {
// 	pthread_mutex_destroy(&(manager->action_locker));
// 	pthread_mutex_destroy(&(manager->speak_locker));
// }

void	clean_table(t_table *table)
{
	// t_dinner_config *const	config = get_config(NULL);

	(void)table;
	// free(config->threads);
	// free(table->philosophers);
	// clean_forks(table->forks, config->nb_philosopher);
}
	// clean_manager(&(table->manager));
