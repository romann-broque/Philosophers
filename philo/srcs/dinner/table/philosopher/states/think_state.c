/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/08 09:26:27 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_state(
	t_philosopher *philo,
	__attribute__((unused))t_dinner_config *config
	)
{
	set_philo_state(philo, E_THINK);
	if (config->nb_philosopher % 2 == 1)
	{
		if (philo->id % (config->nb_philosopher / 2))
			exec_action(config->eat_time / 2);
	}
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
		print_philo_action(philo, THINK_MESSAGE);
}
