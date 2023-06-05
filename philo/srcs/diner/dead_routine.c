/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/05 12:12:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	reset_time(t_philo *philo)
{
	struct timeval	start;

	philo->time_since_last_diner = 0;
	gettimeofday(&start, NULL);
	philo->start_diner_time = start.tv_usec;
}

static void	update_time(t_philo *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	philo->time_since_last_diner = tv.tv_usec - philo->start_diner_time;
}

static bool	is_dead(t_philo *philo)
{
	if (philo->time_since_last_diner >= philo->die_time)
	{
		print_philo_act(philo, DEAD_MESSAGE);
		philo->state = E_DEAD;
		return (true);
	}
	return (false);
}

static void	*dead_philo_routine(t_philo *philo)
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

void	*dead_routine(t_table *table)
{
	const size_t	nb_philo = table->stats->nb_philo;
	t_philo *const	philo_array = table->philo_array;
	size_t			i;

	wait_start(&(table->can_start));
	while (true)
	{
		pthread_mutex_lock(&(table->action_mutex));
		i = 0;
		while (i < nb_philo)
		{
			if (dead_philo_routine(philo_array + i) == NULL)
			{
				table->sbd_dead = true;
				return (NULL);
			}
			++i;
		}
		pthread_mutex_unlock(&(table->action_mutex));
	}
}
