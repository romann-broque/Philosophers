/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/16 00:27:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_state(t_philosopher *philo, t_dinner_config *config)
{
	if (is_philo_alive(philo) == true)
	{
		set_philo_state(philo, E_SLEEP);
		print_philo_action(philo, SLEEP_MESSAGE);
		exec_action(config->sleep_time);
	}
}
