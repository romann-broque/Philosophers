/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/16 00:27:16 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_state(
	t_philosopher *philo,
	__attribute__((unused))t_dinner_config *config
	)
{
	if (is_philo_alive(philo) == true)
	{
		set_philo_state(philo, E_THINK);
		print_philo_action(philo, THINK_MESSAGE);
	}
}
