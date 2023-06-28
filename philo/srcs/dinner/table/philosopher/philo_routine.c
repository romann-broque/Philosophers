/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 14:35:39 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dinner_finished(
	const t_philosopher *philo,
	t_manager *manager,
	const t_dinner_config *config
	)
{
	bool	is_over;

	pthread_mutex_lock(&(manager->is_over_locker));
	is_over = (philo->nb_dinner_eaten == config->nb_dinner
			|| manager->is_a_philosopher_dead == true);
	pthread_mutex_unlock(&(manager->is_over_locker));
	return (is_over);
}

static void	wait_start(t_manager *manager)
{
	pthread_mutex_lock(&(manager->action_locker));
	while (manager->can_dinner_start == false)
	{
		pthread_mutex_unlock(&(manager->action_locker));
		usleep(100);
		pthread_mutex_lock(&(manager->action_locker));
	}
	pthread_mutex_unlock(&(manager->action_locker));
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
	wait_start(manager);
	pthread_mutex_lock(&(manager->state_locker));
	philo->time_since_last_dinner = manager->start_dinner_time;
	pthread_mutex_unlock(&(manager->state_locker));
	while (is_dinner_finished(philo, manager, config) == false)
	{
		state_fct[state_index](philo, config);
		if (state_index + 1 < STATE_NB)
			++state_index;
		else
			state_index = 0;
	}
	return (NULL);
}
