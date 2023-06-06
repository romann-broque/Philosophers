/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:45:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/06 13:23:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->action_mutex);
	while (philo->left_diner > 0)
	{
		pthread_mutex_unlock(philo->action_mutex);
		pthread_mutex_lock(philo->action_mutex);
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
		pthread_mutex_unlock(philo->action_mutex);
		pthread_mutex_lock(philo->action_mutex);
	}
	pthread_mutex_unlock(philo->action_mutex);
	return (NULL);
}
