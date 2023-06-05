/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:35:11 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/05 12:37:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reset_time(t_philo *philo)
{
	struct timeval	start;

	philo->time_since_last_diner = 0;
	gettimeofday(&start, NULL);
	philo->start_diner_time = start.tv_usec;
}

void	update_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	philo->time_since_last_diner = tv.tv_usec - philo->start_diner_time;
}

bool	is_dead(t_philo *philo)
{
	if (philo->time_since_last_diner >= philo->die_time)
	{
		print_philo_act(philo, DEAD_MESSAGE);
		philo->state = E_DEAD;
		return (true);
	}
	return (false);
}

void	*dead_philo_routine(t_philo *philo)
{
	if (philo->start_diner_time == -1 || philo->state == E_EAT)
		reset_time(philo);
	if (philo->state != E_EAT)
	{
		update_time(philo);
		if (is_dead(philo) == true)
			return (NULL);
	}
	return (philo);
}

bool	is_diner_finished(t_table *table)
{
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	i = 0;
	while (i < table->stats->nb_philo)
	{
		if (philo_array[i].left_diner > 0)
			return (false);
		++i;
	}
	return (true);
}
