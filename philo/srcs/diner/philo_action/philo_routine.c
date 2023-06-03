/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:45:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/03 16:03:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	get_time_elapsed(
	t_philo *philo,
	struct timeval *start,
	struct timeval *tv
	)
{
	if (philo->state == E_EAT)
	{
		gettimeofday(start, NULL);
		philo->time_since_last_diner = 0;
	}
	else
	{
		gettimeofday(tv, NULL);
		philo->time_since_last_diner += tv->tv_usec - start->tv_usec;
	}
}

void	*dead_philo_routine(t_philo *philo)
{
	struct timeval	start;
	struct timeval	tv;

	gettimeofday(&start, NULL);
	while (philo->state != E_DEAD && philo->diner_left > 0)
	{
		get_time_elapsed(philo, &start, &tv);
		if (philo->time_since_last_diner >= philo->die_time)
			philo->state = E_DEAD;
	}
	if (philo->state == E_DEAD)
	{
		print_philo_act(philo, DIE_MESSAGE);
		return (NULL);
	}
	return (philo);
}

static void	wait_start(t_philo *philo)
{
	while (*(philo->start) == false)
		;
}

void	*philo_routine(t_philo *philo)
{
	size_t	i;

	wait_start(philo);
	pthread_create(&(philo->dead_thread),
		NULL, (void *(*)(void *))dead_philo_routine, philo);
	while (philo->diner_left > 0 && philo->state != E_DEAD)
	{
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
		++i;
	}
	if (philo->state == E_DEAD)
		return (NULL);
	pthread_detach(philo->dead_thread);
	return (philo);
}
