/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 08:34:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void wait_for_philosophers_deaths(t_philosopher *philosophers, const t_dinner_config *config)
{
	size_t i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		while (get_philo_state(philosophers + i) != E_DEAD);
		++i;
	}
}


static void kill_all_philos(t_philosopher *philosophers, size_t first_id_philo_dead, const t_dinner_config *config)
{
	size_t i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		set_philo_state(philosophers + i, E_PREPARE_TO_DIE);
		if (i == first_id_philo_dead)
			print_philo_action(philosophers + i, DEAD_MESSAGE);
		++i;
	}
	wait_for_philosophers_deaths(philosophers, config);
}

static bool	philosopher_should_die(t_philosopher *philo, const t_dinner_config *config)
{
	t_manager *const	manager = get_manager();
	size_t				time;
	bool				should_a_philosopher_die;
	
	should_a_philosopher_die = false;
	pthread_mutex_lock(&(manager->is_over_locker));
	time = delta_time(philo->time_since_last_dinner);
	if (time >= config->die_time)
	{
		should_a_philosopher_die = true;
		manager->is_a_philosopher_dead = should_a_philosopher_die;
	}
	pthread_mutex_unlock(&(manager->is_over_locker));
	return (should_a_philosopher_die);
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
		if (philosopher_should_die(philosophers + i, config) == true) {
			kill_all_philos(philosophers, i, config);
			return (true);
		}
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
	while (i < config->nb_philosopher && get_philo_state(philosophers + i) == E_FINISHED) {
		++i;
	}
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
	//t_manager *const	manager = &(table->manager);

	//pthread_mutex_lock(&(manager->action_locker));
	while (is_simulation_finished(table->philosophers, config) == false);
	//{
		//pthread_mutex_unlock(&(manager->action_locker));
		//pthread_mutex_lock(&(manager->action_locker));
	//}
	//pthread_mutex_unlock(&(manager->action_locker));
}
