/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 16:50:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dinner_finished(
	const t_philosopher *philo,
	t_manager *manager,
	const t_dinner_config *config
	)
{
	bool	is_over;

	pthread_mutex_lock(&(manager->action_locker));
	is_over = (philo->nb_dinner_eaten < config->nb_dinner
			&& manager->is_a_philosopher_dead == false);
	pthread_mutex_unlock(&(manager->action_locker));
	return (is_over);
}

void	*philo_routine(t_philosopher *philo)
{
	t_dinner_config *const	config = get_config(NULL);
	t_manager *const		manager = get_manager(NULL);

	philo->time_since_last_dinner = manager->start_dinner_time;
	while (is_dinner_finished(philo, manager, config) == false)
	{
		eat_state(philo, config);
		sleep_state(philo, config);
		think_state(philo, config);
	}
	return (NULL);
}
