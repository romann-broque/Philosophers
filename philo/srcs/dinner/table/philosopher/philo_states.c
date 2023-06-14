/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:42:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 16:55:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_forks(t_philosopher *philo)
{
	t_manager *const	manager = get_manager(NULL);

	pthread_mutex_lock(&(manager->eat_locker));
	pthread_mutex_lock(philo->left_fork);
	print_philo_action(philo, FORK_MESSAGE);
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(philo, FORK_MESSAGE);
	pthread_mutex_unlock(&(manager->eat_locker));
}

static void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_state(t_philosopher *philo, t_dinner_config *config)
{
	if (philo->state == E_DEAD)
		return ;
	grab_forks(philo);
	set_philo_state(philo, E_EAT);
	print_philo_action(philo, EAT_MESSAGE);
	philo->time_since_last_dinner = get_time();
	exec_action(config->eat_time);
	++(philo->nb_dinner_eaten);
	drop_forks(philo);
}

void	sleep_state(t_philosopher *philo, t_dinner_config *config)
{
	if (philo->state == E_DEAD)
		return ;
	set_philo_state(philo, E_SLEEP);
	print_philo_action(philo, SLEEP_MESSAGE);
	exec_action(config->sleep_time);
}

void	think_state(
	t_philosopher *philo,
	__attribute__((unused))t_dinner_config *config
	)
{
	if (philo->state == E_DEAD)
		return ;
	set_philo_state(philo, E_THINK);
	print_philo_action(philo, THINK_MESSAGE);
}
