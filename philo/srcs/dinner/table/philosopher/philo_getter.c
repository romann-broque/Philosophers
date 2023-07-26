/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:30:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:30:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

enum e_state	get_philo_state(t_philosopher *philo)
{
	enum e_state	state;

	pthread_mutex_lock(&(philo->state_locker));
	state = philo->state;
	pthread_mutex_unlock(&(philo->state_locker));
	return (state);
}

size_t	get_nb_dinner_eaten(t_philosopher *philo)
{
	size_t	nb_dinner_eaten;

	pthread_mutex_lock(&(philo->nb_dinner_locker));
	nb_dinner_eaten = philo->nb_dinner_eaten;
	pthread_mutex_unlock(&(philo->nb_dinner_locker));
	return (nb_dinner_eaten);
}

size_t	get_time_since_last_dinner(t_philosopher *philo)
{
	size_t	time_since_last_dinner;

	pthread_mutex_lock(&(philo->time_locker));
	time_since_last_dinner = philo->time_since_last_dinner;
	pthread_mutex_unlock(&(philo->time_locker));
	return (time_since_last_dinner);
}