/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 09:26:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void grab_specific_fork(t_philosopher *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
		print_philo_action(philo, FORK_MESSAGE);
}

static int	grab_forks(t_philosopher *philo)
{

	grab_specific_fork(philo, philo->forks[0]);
	if (philo->forks[0] == philo->forks[1])
		return FAILURE;
	grab_specific_fork(philo, philo->forks[1]);
	return SUCCESS;
}

static void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->forks[0]);
	if (philo->forks[0] != philo->forks[1])
		pthread_mutex_unlock(philo->forks[1]);
}

static void	reset_eat_status(t_philosopher *philo)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->is_over_locker));
	philo->time_since_last_dinner = get_time();
	pthread_mutex_unlock(&(manager->is_over_locker));
}

static void	increase_meal_count(t_philosopher *philo)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->action_locker));
	++(philo->nb_dinner_eaten);
	pthread_mutex_unlock(&(manager->action_locker));
}

void	eat_state(t_philosopher *philo, t_dinner_config *config)
{
	if (grab_forks(philo) == FAILURE)
		set_philo_state(philo, E_PREPARE_TO_DIE);
	else if (get_philo_state(philo) != E_PREPARE_TO_DIE)
	{
		reset_eat_status(philo);
		set_philo_state(philo, E_EAT);
		print_philo_action(philo, EAT_MESSAGE);
		exec_action(config->eat_time);
		increase_meal_count(philo);
		if (philo->nb_dinner_eaten == config->nb_dinner) {
			set_philo_state(philo, E_FINISHED);
		}
	}
	drop_forks(philo);
}
