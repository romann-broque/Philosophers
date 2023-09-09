/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/09 07:59:12 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think_waiting(
	const t_dinner_config *config
	)
{
	static size_t	turn_wait = 0;

	if (config->nb_philosopher % 2 == 1)
	{
		exec_action(config->eat_time / 2);
		++turn_wait;
	}
}

void	think_state(
	t_philosopher *philo,
	t_dinner_config *config
	)
{
	set_philo_state(philo, E_THINK);
	think_waiting(config);
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
		print_philo_action(philo, THINK_MESSAGE);
}
