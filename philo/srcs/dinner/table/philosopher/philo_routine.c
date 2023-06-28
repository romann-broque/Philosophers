/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 10:14:02 by rbroque          ###   ########.fr       */
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
	t_dinner_config *const	config = get_config(NULL);
	t_manager *const		manager = get_manager(NULL);

	wait_start(manager);
	pthread_mutex_lock(&(manager->state_locker));
	philo->time_since_last_dinner = manager->start_dinner_time;
	pthread_mutex_unlock(&(manager->state_locker));
	while (is_dinner_finished(philo, manager, config) == false)
	{
		eat_state(philo, config);
		sleep_state(philo, config);
		think_state(philo, config);
	}
	return (NULL);
}
