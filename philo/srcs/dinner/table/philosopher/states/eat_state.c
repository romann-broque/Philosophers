/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 14:19:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_forks(t_philosopher *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->left_fork);
		print_philo_action(philo, FORK_MESSAGE);
		pthread_mutex_lock(philo->right_fork);
		print_philo_action(philo, FORK_MESSAGE);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_philo_action(philo, FORK_MESSAGE);
		pthread_mutex_lock(philo->left_fork);
		print_philo_action(philo, FORK_MESSAGE);
	}
}

static void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	reset_eat_status(t_philosopher *philo)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->action_locker));
	philo->time_since_last_dinner = get_time();
	pthread_mutex_unlock(&(manager->action_locker));
}

static void increase_meal_count(t_philosopher *philo)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->action_locker));
	++(philo->nb_dinner_eaten);
	pthread_mutex_unlock(&(manager->action_locker));
}

void	eat_state(t_philosopher *philo, t_dinner_config *config)
{
	grab_forks(philo);
	reset_eat_status(philo);
	set_philo_state(philo, E_EAT);
	print_philo_action(philo, EAT_MESSAGE);
	exec_action(config->eat_time);
	drop_forks(philo);
	increase_meal_count(philo);
}
