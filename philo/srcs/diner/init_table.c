/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:36:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/02 13:28:32 by rbroque          ###   ########.fr       */
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

static t_philo	*init_philo_array(const size_t nb_philo, t_fork *forks)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)malloc(nb_philo * sizeof(t_philo));
	if (philo_array != NULL)
		fill_philo_array(philo_array, forks, nb_philo);
	return (philo_array);
}

void	init_table(t_table *table, t_stat *stats)
{
	table->forks = init_forks(stats->nb_philo);
	if (table->forks != NULL)
		table->philo_array = init_philo_array(stats->nb_philo, table->forks);
	table->stats = stats;
}
