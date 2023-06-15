/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/16 00:23:56 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_philosopher *philo, const t_dinner_config *config)
{
	t_manager *const	manager = get_manager(NULL);
	size_t				time;

	pthread_mutex_lock(&(manager->state_locker));
	pthread_mutex_lock(&(manager->is_over_locker));
	time = delta_time(philo->time_since_last_dinner);
	if (time >= config->die_time)
	{
		manager->is_a_philosopher_dead = true;
		pthread_mutex_unlock(&(manager->is_over_locker));
		pthread_mutex_unlock(&(manager->state_locker));
		print_philo_action(philo, DEAD_MESSAGE);
		set_philo_state(philo, E_DEAD);
		return (true);
	}
	pthread_mutex_unlock(&(manager->is_over_locker));
	pthread_mutex_unlock(&(manager->state_locker));
	return (false);
}

static bool	is_a_philo_dead(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		if (is_dead(philosophers + i, config) == true)
			return (true);
		++i;
	}
	return (false);
}

static bool	are_dinners_finished(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher
		&& philosophers[i].nb_dinner_eaten == config->nb_dinner)
		++i;
	return (i == config->nb_philosopher);
}

static bool	is_simulation_finished(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	return (is_a_philo_dead(philosophers, config)
		|| are_dinners_finished(philosophers, config));
}

void	manager_routine(t_table *table, const t_dinner_config *config)
{
	t_manager *const	manager = &(table->manager);

	pthread_mutex_lock(&(manager->action_locker));
	while (is_simulation_finished(table->philosophers, config) == false)
	{
		pthread_mutex_unlock(&(manager->action_locker));
		pthread_mutex_lock(&(manager->action_locker));
	}
	pthread_mutex_unlock(&(manager->action_locker));
}
