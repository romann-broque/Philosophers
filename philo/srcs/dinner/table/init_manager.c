/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:47:56 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 22:02:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_manager(t_manager *manager)
{
	pthread_mutex_init(&(manager->speak_locker), NULL);
	pthread_mutex_init(&(manager->action_locker), NULL);
	pthread_mutex_init(&(manager->eat_locker), NULL);
	manager->is_a_philosopher_dead = false;
	manager->can_dinner_start = false;
}
