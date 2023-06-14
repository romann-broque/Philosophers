/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:31:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 10:38:38 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philosopher *philo, const char *message)
{
	t_manager *const	manager = get_manager(NULL);
	size_t				now;

	pthread_mutex_lock(&(manager->speak_locker));
	now = delta_time(philo->time_since_last_dinner);
	printf("%zu %zu %s\n", now, philo->id, message);
	pthread_mutex_unlock(&(manager->speak_locker));
}
