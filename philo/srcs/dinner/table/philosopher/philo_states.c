/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:42:26 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 11:01:03 by rbroque          ###   ########.fr       */
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
	grab_forks(philo);
	philo->state = E_EAT;
	print_philo_action(philo, EAT_MESSAGE);
	philo->time_since_last_dinner = get_time();
	exec_action(config->eat_time);
	++(philo->nb_dinner_eaten);
	drop_forks(philo);
}
