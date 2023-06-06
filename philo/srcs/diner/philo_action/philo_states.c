/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:30:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/06 14:38:34 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_fork(t_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&(fork->mutex));
	print_philo_act(philo, FORK_MESSAGE);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}

void	eat_state(t_philo *philo)
{
	philo->time_count = get_time();
	grab_fork(philo->left_fork, philo);
	grab_fork(philo->right_fork, philo);
	philo->state = E_EAT;
	print_philo_act(philo, EAT_MESSAGE);
	exec_action(philo->eat_time);
	drop_forks(philo);
	--(philo->left_diner);
}

void	sleep_state(t_philo *philo)
{
	philo->state = E_SLEEP;
	print_philo_act(philo, SLEEP_MESSAGE);
	exec_action(philo->eat_time);
}

void	think_state(t_philo *philo)
{
	print_philo_act(philo, THINK_MESSAGE);
	philo->state = E_THINK;
}
