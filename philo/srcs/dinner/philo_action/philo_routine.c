/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:45:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/09 14:42:06 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	delay_even(t_philo *philo)
{
	if (philo->index % 2)
		exec_action(1);
}

void	*philo_routine(t_philo *philo)
{
	while (philo->left_dinner > 0)
	{
		delay_even(philo);
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
	}
	return (NULL);
}
