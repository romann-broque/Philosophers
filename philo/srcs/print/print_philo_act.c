/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:33:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/03 20:12:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_act(t_philo *philo, const char *action)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&(philo->print_mutex));
	printf("%ld %zu %s\n", tv.tv_usec, philo->index, action);
	pthread_mutex_unlock(&(philo->print_mutex));
}
