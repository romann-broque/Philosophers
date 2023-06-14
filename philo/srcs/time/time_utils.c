/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:16:18 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 10:39:57 by rbroque          ###   ########.fr       */
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

void	exec_action(const size_t micro_seconds)
{
	usleep(1000 * micro_seconds);
}
