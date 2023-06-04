/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:45:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/04 22:35:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dead_routine(t_philo *philo)
{
	struct timeval	start;
	struct timeval	tv;

	gettimeofday(&start, NULL);
	while (true)
	{
		if (philo->state != E_EAT)
		{
			gettimeofday(&tv, NULL);
			philo->time_since_last_diner = tv.tv_usec - start.tv_usec;
			if (philo->time_since_last_diner >= philo->die_time)
			{
				print_philo_act(philo, DEAD_MESSAGE);
				philo->state = E_DEAD;
				return (NULL);
			}
		}
		else
		{
			gettimeofday(&start, NULL);
			philo->time_since_last_diner = 0;
		}
	}
}

static void	wait_start(t_philo *philo)
{
	while (*(philo->can_start) == false)
		;
}

void	*philo_routine(t_philo *philo)
{
	wait_start(philo);
	pthread_create(&(philo->dead_thread), NULL,
		(void *(*)(void *))dead_routine, philo);
	while (philo->left_diner > 0)
	{
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
	}
	return (NULL);
}
