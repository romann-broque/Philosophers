/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:01:28 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dinner_finished(t_philosopher *philo)
{
	return (get_philo_state(philo) == E_FINISHED);
}

void	*philo_routine(t_philosopher *philo)
{
	static void				(*state_fct[])(
			t_philosopher *,
			t_dinner_config *) = {
		eat_state,
		sleep_state,
		think_state
	};
	t_dinner_config *const	config = get_config(NULL);
	t_manager *const		manager = get_manager();
	size_t					state_index;

	state_index = 0;
	pthread_mutex_lock(&(manager->is_over_locker));
	// timelocker
	philo->time_since_last_dinner = manager->start_dinner_time;
	pthread_mutex_unlock(&(manager->is_over_locker));
	while (is_dinner_finished(philo) == false && get_philo_state(philo) != E_PREPARE_TO_DIE)
	{
		state_fct[state_index % STATE_NB](philo, config);
	}
	if (get_philo_state(philo) == E_PREPARE_TO_DIE)
		set_philo_state(philo, E_DEAD);
	return (NULL);
}
