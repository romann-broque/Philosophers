/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:41:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_dinner_finished(t_philosopher *philo)
{
	const enum e_state	state = get_philo_state(philo);

	return (state == E_FINISHED || state == E_PREPARE_TO_DIE);
}

void	*philo_routine(t_philosopher *philo)
{
	static void				(*state_fct[])(
			t_philosopher *,
			t_dinner_config *) = {
		eat_state,
		sleep_state,
		think_state
	};
	t_dinner_config *const	config = get_config(NULL);
	size_t					state_index;

	state_index = 0;
	set_time_since_last_dinner(philo, get_start_dinner_time());
	while (is_dinner_finished(philo) == false)
	{
		state_fct[state_index % STATE_NB](philo, config);
		++state_index;
	}
	if (get_philo_state(philo) == E_PREPARE_TO_DIE)
		set_philo_state(philo, E_DEAD);
	return (NULL);
}
