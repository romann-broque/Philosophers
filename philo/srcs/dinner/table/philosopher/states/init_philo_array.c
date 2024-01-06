/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:59:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/03 16:02:42 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(
	t_philo *philo,
	const size_t index,
	t_fork *left_fork,
	t_fork *right_fork
	)
{
	philo->index = index;
	philo->state = E_THINK;
	philo->left_fork = left_fork;
	philo->right_fork = right_fork;
}

static void	fill_philo_array(
	t_philo *philo_array,
	t_fork *forks,
	const size_t nb_philo
	)
{
	size_t	i;

	i = 0;
	while (i < nb_philo)
	{
		if (i + 1 == nb_philo)
			init_philo(philo_array + i, i + 1, forks + i, forks);
		else
			init_philo(philo_array + i, i + 1, forks + i, forks + i + 1);
		++i;
	}
}

static void	set_philo_settings(t_philo *philo, t_table *table)
{
	t_stat *const	stats = table->stats;

	philo->eat_time = stats->eat_time;
	philo->die_time = stats->die_time;
	philo->sleep_time = stats->sleep_time;
	philo->time_since_last_diner = 0;
	philo->diner_left = stats->nb_diner;
	philo->start = &(table->start);
	pthread_mutex_init(&(philo->print_mutex), NULL);
}

void	set_philo_array_stats(t_philo *philo_array, t_table *table)
{
	t_stat *const	stats = table->stats;
	size_t			i;

	i = 0;
	while (i < stats->nb_philo)
	{
		set_philo_settings(philo_array + i, table);
		++i;
	}
}

t_philo	*init_philo_array(const size_t nb_philo, t_fork *forks)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)malloc(nb_philo * sizeof(t_philo));
	if (philo_array != NULL)
		fill_philo_array(philo_array, forks, nb_philo);
	return (philo_array);
}
