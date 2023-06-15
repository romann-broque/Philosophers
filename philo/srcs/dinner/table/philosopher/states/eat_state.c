/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/15 23:41:02 by rbroque          ###   ########.fr       */
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

static void	reset_eat_status(t_philosopher *philo)
{
	t_manager *const	manager = get_manager(NULL);

	pthread_mutex_lock(&(manager->action_locker));
	pthread_mutex_lock(&(manager->state_locker));
	philo->time_since_last_dinner = get_time();
	++(philo->nb_dinner_eaten);
	pthread_mutex_unlock(&(manager->state_locker));
	pthread_mutex_unlock(&(manager->action_locker));
}

void	eat_state(t_philosopher *philo, t_dinner_config *config)
{
	if (philo->state == E_DEAD)
		return ;
	grab_forks(philo);
	set_philo_state(philo, E_EAT);
	print_philo_action(philo, EAT_MESSAGE);
	reset_eat_status(philo);
	exec_action(config->eat_time);
	drop_forks(philo);
}
