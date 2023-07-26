/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 08:46:55 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_state(t_philosopher *philo, const enum e_state state)
{

	pthread_mutex_lock(&(philo->state_locker));
	if ((philo->state != E_PREPARE_TO_DIE
		&& philo->state != E_DEAD
		&& philo->state != E_FINISHED)
		|| state == E_DEAD)
		philo->state = state;
	pthread_mutex_unlock(&(philo->state_locker));
}

enum e_state	get_philo_state(t_philosopher *philo)
{
	enum e_state	state;

	pthread_mutex_lock(&(philo->state_locker));
	state = philo->state;
	pthread_mutex_unlock(&(philo->state_locker));
	return (state);
}
