/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:24:22 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 14:58:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_able_to_print(t_philosopher *philosopher)
{
	return (get_philo_state(philosopher) != E_PREPARE_TO_DIE);
}

void	print_philo_action(
	t_philosopher *philo,
	const char *message
	)
{
	t_manager *const	manager = get_manager();
	size_t				now;

	now = delta_time(get_start_dinner_time());
	pthread_mutex_lock(&(manager->speak_locker));
	if (is_able_to_print(philo))
		printf("%zu %zu %s\n", now, philo->id, message);
	pthread_mutex_unlock(&(manager->speak_locker));
}
