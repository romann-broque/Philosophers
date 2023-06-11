/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:35:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/11 23:06:09 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_philo *philo, t_stat *stats)
{
	size_t	time;

	time = delta_time(philo->time_count);
	if (time >= stats->die_time)
	{
		print_philo_act(philo, RED""DEAD_MESSAGE""NC);
		philo->state = E_DEAD;
		return (true);
	}
	return (false);
}

void	*dead_philo_routine(t_philo *philo, t_stat *stats)
{
	if (is_dead(philo, stats) == true)
		return (NULL);
	return (philo);
}

bool	is_dinner_finished(t_table *table)
{
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	pthread_mutex_lock(&(table->action_mutex));
	i = 0;
	while (i < table->stats->nb_philo)
	{
		if (philo_array[i].left_dinner > 0)
		{
			pthread_mutex_unlock(&(table->action_mutex));
			return (false);
		}
		++i;
	}
	pthread_mutex_unlock(&(table->action_mutex));
	return (true);
}
