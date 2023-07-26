/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:47:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 12:33:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_manager(t_manager *manager)
{
	manager->start_dinner_time = 0;
	pthread_mutex_init(&(manager->speak_locker), NULL);
	pthread_mutex_init(&(manager->start_time_locker), NULL);
	pthread_mutex_init(&(manager->can_start_locker), NULL);
	manager->is_a_philosopher_dead = false;
}
