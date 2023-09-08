/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:41:51 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/08 08:57:40 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think_state(
	t_philosopher *philo,
	__attribute__((unused))t_dinner_config *config
	)
{
	static size_t	think_turn = 0;

	set_philo_state(philo, E_THINK);
	if (config->nb_philosopher % 2 == 1)
	{
		if (think_turn == 0)
			think_turn = philo->id;
		if ((think_turn + philo->id) % 2 == 0)
			exec_action(config->eat_time / 2);
		++think_turn;
	}
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
		print_philo_action(philo, THINK_MESSAGE);
}
