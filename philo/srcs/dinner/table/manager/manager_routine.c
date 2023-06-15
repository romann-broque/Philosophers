/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/15 22:55:13 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dead(t_philosopher *philo, const t_dinner_config *config)
{
	t_manager *const	manager = get_manager(NULL);
	size_t				time;

	time = delta_time(philo->time_since_last_dinner);
	if (time >= config->die_time)
	{
		print_philo_action(philo, DEAD_MESSAGE);
		set_philo_state(philo, E_DEAD);
		manager->is_a_philosopher_dead = true;
	}
	return (philo->state == E_DEAD);
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
			break ;
		++i;
	}
	return (i < config->nb_philosopher);
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
