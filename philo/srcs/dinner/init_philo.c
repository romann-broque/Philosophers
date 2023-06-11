/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:40:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/11 22:02:05 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(
	t_philo *philo,
	const size_t id,
	t_fork **forks,
	t_table *table
	)
{
	philo->index = id;
	philo->state = E_THINK;
	philo->left_fork = forks[0];
	philo->right_fork = forks[1];
	philo->left_dinner = table->stats->nb_dinner;
	philo->sleep_time = table->stats->sleep_time;
	philo->eat_time = table->stats->eat_time;
	philo->time_count = 0;
	philo->start_time = &(table->start_time);
	philo->sbd_dead = &(table->sbd_dead);
	philo->can_start = &(table->can_start);
	pthread_mutex_init(&(philo->print_mutex), NULL);
}

static void	fill_philo_array(
	t_philo *philo_array,
	t_table *table,
	const size_t nb_philo
	)
{
	t_fork *const	forks_array = table->forks;
	t_fork			*forks[2];
	size_t			id;
	size_t			i;

	i = 0;
	while (i < nb_philo)
	{
		id = i + 1;
		forks[0] = forks_array + i;
		forks[1] = forks_array + id % nb_philo;
		init_philo(philo_array + i, id, forks, table);
		++i;
	}
}

t_philo	*init_philo_array(const size_t nb_philo, t_table *table)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)malloc(nb_philo * sizeof(t_philo));
	if (philo_array != NULL)
		fill_philo_array(philo_array, table, nb_philo);
	return (philo_array);
}
