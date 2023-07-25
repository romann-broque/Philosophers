/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:24:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/25 22:08:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_action(t_philosopher *philo, const char *message)
{
	t_manager *const	manager = get_manager();
	size_t				now;
	now = delta_time(manager->start_dinner_time);
	pthread_mutex_lock(&(manager->speak_locker));

	printf("%zu %zu %s\n", now, philo->id, message);
	pthread_mutex_unlock(&(manager->speak_locker));
}
