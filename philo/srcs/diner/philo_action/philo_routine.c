/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:45:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/05 11:59:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_start(bool *can_start)
{
	while (*can_start == false)
		;
}

void	*philo_routine(t_philo *philo)
{
	wait_start(philo->can_start);
	pthread_mutex_lock(philo->action_mutex);
	while (philo->left_diner > 0 && *(philo->sbd_dead) == false)
	{
		pthread_mutex_unlock(philo->action_mutex);
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
		pthread_mutex_lock(philo->action_mutex);
	}
	pthread_mutex_unlock(philo->action_mutex);
	return (NULL);
}
