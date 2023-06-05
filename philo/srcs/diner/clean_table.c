/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:37:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/05 18:19:17 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	clean_forks(t_table *table)
{
	const size_t	nb_forks = table->stats->nb_philo;
	t_fork *const	forks = table->forks;
	size_t			i;

	i = 0;
	while (i < nb_forks)
	{
		pthread_mutex_destroy(&(forks[i].mutex));
		++i;
	}
}

static void	clean_philo(t_table *table)
{
	const size_t	nb_forks = table->stats->nb_philo;
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	i = 0;
	while (i < nb_forks)
	{
		if (philo_array[i].state != E_DEAD)
			pthread_detach(philo_array[i].thread);
		++i;
	}
	free(table->philo_array);
}

void	clean_table(t_table *table)
{
	clean_forks(table);
	clean_philo(table);
	free(table->forks);
	pthread_mutex_destroy(&(table->action_mutex));
}
