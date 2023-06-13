/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 01:47:30 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 01:57:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_a_philo_dead(
	t_philosopher *philosophers,
	const size_t nb_philosopher
	)
{
	size_t	i;

	i = 0;
	while (i < nb_philosopher && philosophers[i].state != E_DEAD)
		++i;
	return (i < nb_philosopher);
}

static bool	are_dinners_finished(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher
		&& philosophers[i].nb_dinner_eaten == config->nb_dinner)
		++i;
	return (i == config->nb_philosopher);
}

static bool	is_simulation_finished(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	return (is_a_philo_dead(philosophers, config->nb_philosopher)
		|| are_dinners_finished(philosophers, config));
}

void	manager_routine(t_table *table, const t_dinner_config *config)
{
	while (is_simulation_finished(table->philosophers, config) == false)
		;
}
