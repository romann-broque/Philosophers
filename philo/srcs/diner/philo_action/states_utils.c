/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:30:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/06 14:30:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_fork(t_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&(fork->mutex));
	print_philo_act(philo, FORK_MESSAGE);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->left_fork->mutex));
	pthread_mutex_unlock(&(philo->right_fork->mutex));
}

void	exec_action(const suseconds_t ms)
{
	usleep(1000 * ms);
}
