/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:47:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 16:47:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_manager(t_manager *manager)
{
	manager->start_dinner_time = 0;
	pthread_mutex_init(&(manager->speak_locker), NULL);
	pthread_mutex_init(&(manager->action_locker), NULL);
	pthread_mutex_init(&(manager->eat_locker), NULL);
	pthread_mutex_init(&(manager->state_locker), NULL);
	manager->is_a_philosopher_dead = false;
	manager->can_dinner_start = false;
}
