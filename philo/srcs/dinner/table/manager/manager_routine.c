/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 14:39:01 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_a_philo_dead(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		if (philosopher_should_die(philosophers + i, config) == true)
		{
			kill_all_philos(philosophers, i, config);
			return (true);
		}
		++i;
	}
	return (false);
}

static bool	are_dinners_finished(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher
		&& get_philo_state(philosophers + i) == E_FINISHED)
		++i;
	return (i == config->nb_philosopher);
}

static bool	is_simulation_finished(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	return (are_dinners_finished(philosophers, config)
		|| is_a_philo_dead(philosophers, config));
}

void	manager_routine(t_table *table, const t_dinner_config *config)
{
	while (is_simulation_finished(table->philosophers, config) == false)
		usleep(TEMPO_TIME);
}
