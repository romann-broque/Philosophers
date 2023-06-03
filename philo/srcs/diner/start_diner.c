/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_diner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:21:37 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/03 15:41:46 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_philo(t_philo	*philo)
{
	pthread_create(&(philo->thread),
		NULL, (void *(*)(void *))philo_routine, philo);
}

static void	wait_philo(t_table *table)
{
	void	*philo_status;
	size_t	i;

	i = 0;
	while (i < table->stats->nb_philo)
	{
		philo_status = &(table->philo_array[i].thread);
		pthread_join(table->philo_array[i].thread, &philo_status);
		if (philo_status == NULL)
		{
			printf("STOOOOOOP\n");
			break ;
		}
		++i;
	}
}

static void	launch_simulation(t_table *table)
{
	size_t	i;

	pthread_mutex_lock(&(table->mutex));
	i = 0;
	while (i < table->stats->nb_philo)
	{
		start_philo(table->philo_array + i);
		++i;
	}
	table->start = true;
	wait_philo(table);
	pthread_mutex_unlock(&(table->mutex));
}

void	start_diner(t_stat *stats)
{
	t_table	table;

	init_table(&table, stats);
	print_stat(stats);
	launch_simulation(&table);
	clean_table(&table);
}
