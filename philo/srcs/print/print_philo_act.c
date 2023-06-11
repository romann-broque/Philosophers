/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:33:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/11 22:49:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_act(t_philo *philo, const char *action)
{
	size_t	now;

	if (*(philo->sbd_dead) == false)
	{
		now = delta_time(*(philo->start_time));
		pthread_mutex_lock(&(philo->print_mutex));
		printf("%zu %zu %s\n", now, philo->index, action);
		pthread_mutex_unlock(&(philo->print_mutex));
	}
}
