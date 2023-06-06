/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/06 14:01:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_routine(t_table *table)
{
	const size_t	nb_philo = table->stats->nb_philo;
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	while (is_diner_finished(table) == false)
	{
		pthread_mutex_lock(&(table->action_mutex));
		i = 0;
		while (i < nb_philo)
		{
			if (dead_philo_routine(philo_array + i, table->stats) == NULL)
			{
				table->sbd_dead = true;
				return (NULL);
			}
			++i;
		}
		pthread_mutex_unlock(&(table->action_mutex));
	}
	return (table);
}
