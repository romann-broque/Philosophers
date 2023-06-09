/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/09 14:36:19 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_routine(t_table *table)
{
	const size_t	nb_philo = table->stats->nb_philo;
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	while (is_dinner_finished(table) == false)
	{
		i = 0;
		while (i < nb_philo)
		{
			pthread_mutex_lock(&(table->action_mutex));
			if (dead_philo_routine(philo_array + i, table->stats) == NULL)
			{
				table->sbd_dead = true;
				return (NULL);
			}
			pthread_mutex_unlock(&(table->action_mutex));
			++i;
		}
	}
	return (table);
}
