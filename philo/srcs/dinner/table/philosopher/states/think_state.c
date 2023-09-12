/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 07:44:30 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_thinking(const t_dinner_config *config)
{
	long	wait_time;

	wait_time = 0;
	if (config->nb_philosopher % 2 == 1 && config->sleep_time <= config->eat_time * 2)
		wait_time = config->eat_time * 2 - config->sleep_time;
	exec_action(wait_time);
}

void	think_state(
	t_philosopher *philo,
	t_dinner_config *config
	)
{
	set_philo_state(philo, E_THINK);
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
	{
		print_philo_action(philo, THINK_MESSAGE);
		wait_thinking(config);
	}
}
