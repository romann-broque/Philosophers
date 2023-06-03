/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:36:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/03 22:42:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_fork	*init_forks(const size_t nb_philo)
{
	t_fork	*forks;
	size_t	i;

	forks = (t_fork *)malloc(nb_philo * sizeof(t_fork));
	if (forks != NULL)
	{
		i = 0;
		while (i < nb_philo)
		{
			forks[i].state = FREE;
			pthread_mutex_init(&(forks[i].mutex), NULL);
			++i;
		}
	}
	return (forks);
}

void	init_table(t_table *table, t_stat *stats)
{
	table->forks = init_forks(stats->nb_philo);
	table->stats = stats;
	if (table->forks != NULL)
	{
		table->philo_array = init_philo_array(stats->nb_philo, table->forks);
		set_philo_settings(table);
	}
}
