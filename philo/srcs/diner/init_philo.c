/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:40:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/03 22:48:32 by rbroque          ###   ########.fr       */
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
	pthread_mutex_init(&(philo->print_mutex), NULL);
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

t_philo	*init_philo_array(const size_t nb_philo, t_fork *forks)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)malloc(nb_philo * sizeof(t_philo));
	if (philo_array != NULL)
		fill_philo_array(philo_array, forks, nb_philo);
	return (philo_array);
}

static void	set_philo_set(t_philo *philo, t_table *table)
{
	philo->left_diner = table->stats->nb_diner;
	philo->sleep_time = table->stats->sleep_time;
	philo->eat_time = table->stats->eat_time;
	philo->time_since_last_diner = 0;
}

void	set_philo_settings(t_table *table)
{
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	i = 0;
	while (i < table->stats->nb_philo)
	{
		set_philo_set(philo_array + i, table);
		++i;
	}
}
