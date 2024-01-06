/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:16:06 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:25:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_start_dinner_time(void)
{
	t_manager *const	manager = get_manager();

	pthread_mutex_lock(&(manager->start_time_locker));
	manager->start_dinner_time = get_time();
	pthread_mutex_unlock(&(manager->start_time_locker));
}

size_t	get_start_dinner_time(void)
{
	t_manager *const	manager = get_manager();
	size_t				start_time;

	pthread_mutex_lock(&(manager->start_time_locker));
	start_time = manager->start_dinner_time;
	pthread_mutex_unlock(&(manager->start_time_locker));
	return (start_time);
}
