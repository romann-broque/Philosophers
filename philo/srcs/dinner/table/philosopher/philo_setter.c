/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:30:05 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:30:12 by rbroque          ###   ########.fr       */
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

void	increase_nb_dinner_eaten(t_philosopher *philo)
{
	pthread_mutex_lock(&(philo->nb_dinner_locker));
	++(philo->nb_dinner_eaten);
	pthread_mutex_unlock(&(philo->nb_dinner_locker));
}

void	set_time_since_last_dinner(t_philosopher *philo, const size_t new_time)
{
	pthread_mutex_lock(&(philo->time_locker));
	philo->time_since_last_dinner = new_time;
	pthread_mutex_unlock(&(philo->time_locker));
}