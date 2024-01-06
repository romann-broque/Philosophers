/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:16:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 16:21:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

size_t	delta_time(long long time)
{
	if (time > 0)
		return (get_time() - time);
	return (0);
}

void	exec_action(t_philosopher *philo, const size_t milliseconds)
{
	size_t	left_time;

	left_time = milliseconds;
	if (DONT_WAIT)
	{
		while (left_time > 0 && get_philo_state(philo) != E_PREPARE_TO_DIE)
		{
			usleep(1000);
			--left_time;
		}
	}
	else
		usleep(1000 * milliseconds);
}
