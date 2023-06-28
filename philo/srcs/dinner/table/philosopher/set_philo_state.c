/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:29 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/28 12:13:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_state(t_philosopher *philo, const enum e_state state)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->state_locker));
	if (philo->state != E_DEAD)
		philo->state = state;
	pthread_mutex_unlock(&(manager->state_locker));
}
