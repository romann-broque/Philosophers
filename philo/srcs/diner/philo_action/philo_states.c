/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:30:33 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/02 14:36:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_fork(t_fork *fork, const size_t philo_id)
{
	pthread_mutex_lock(&(fork->mutex));
	print_philo_act(philo_id, FORK_MESSAGE);
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}

void	eat_state(t_philo *philo)
{
	grab_fork(philo->left_fork, philo->index);
	grab_fork(philo->right_fork, philo->index);
	print_philo_act(philo->index, EAT_MESSAGE);
	philo->state = E_EAT;
	drop_forks(philo);
}

// add a usleep in sleep function

void	sleep_state(t_philo *philo)
{
	print_philo_act(philo->index, SLEEP_MESSAGE);
	philo->state = E_SLEEP;
}

void	think_state(t_philo *philo)
{
	print_philo_act(philo->index, THINK_MESSAGE);
	philo->state = E_THINK;
}
