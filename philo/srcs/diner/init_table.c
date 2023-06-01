/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:36:57 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/01 19:37:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philo(t_philo *philo, const size_t index)
{
	philo->index = index;
	philo->state = E_THINK;
}

static void	fill_philo_array(t_philo *philo_array, const size_t nb_philo)
{
	size_t	i;

	i = 0;
	while (i < nb_philo)
	{
		init_philo(philo_array + i, i);
		++i;
	}
}

static t_philo	*init_philo_array(const size_t nb_philo)
{
	t_philo	*philo_array;

	philo_array = (t_philo *)malloc(nb_philo * sizeof(t_philo));
	if (philo_array != NULL)
		fill_philo_array(philo_array, nb_philo);
	return (philo_array);
}

void	init_table(t_table *table, t_stat *stats)
{
	table->philo_array = init_philo_array(stats->nb_philo);
}
