/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 16:06:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_state(t_philosopher *philo, t_dinner_config *config)
{
	set_philo_state(philo, E_SLEEP);
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
		print_philo_action_by_philo(philo, SLEEP_MESSAGE);
	exec_action(philo, config->sleep_time);
}
