/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:45:04 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/06 15:21:35 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_start(bool *start)
{
	while (*start == false)
		;
}

static void	delay_even(t_philo *philo)
{
	if (philo->index % 2)
		exec_action(1);
}

void	*philo_routine(t_philo *philo)
{
	wait_start(philo->can_start);
	delay_even(philo);
	while (philo->left_diner > 0)
	{
		eat_state(philo);
		sleep_state(philo);
		think_state(philo);
	}
	return (NULL);
}
