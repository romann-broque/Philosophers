/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_diner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:21:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/06 14:16:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philo(t_philo	*philo)
{
	pthread_create(&(philo->thread),
		NULL, (void *(*)(void *))philo_routine, philo);
}

static void	start_threads(t_table *table)
{
	size_t	i;

	pthread_create(&(table->dead_thread), NULL,
		(void *(*)(void *))dead_routine, table);
	i = 0;
	while (i < table->stats->nb_philo)
	{
		start_philo(table->philo_array + i);
		++i;
	}
}

static void	launch_simulation(t_table *table)
{
	table->start_time = get_time();
	start_threads(table);
	pthread_join(table->dead_thread, NULL);
}

void	start_diner(t_stat *stats)
{
	t_table	table;

	init_table(&table, stats);
	print_stat(stats);
	launch_simulation(&table);
	clean_table(&table);
}
