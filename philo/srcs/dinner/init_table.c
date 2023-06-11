/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:36:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/11 22:47:56 by rbroque          ###   ########.fr       */
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
	table->sbd_dead = false;
	table->can_start = false;
	if (table->forks != NULL)
	{
		pthread_mutex_init(&(table->action_mutex), NULL);
		pthread_mutex_init(&(table->eat_mutex), NULL);
		table->philo_array = init_philo_array(stats->nb_philo, table);
	}
}
