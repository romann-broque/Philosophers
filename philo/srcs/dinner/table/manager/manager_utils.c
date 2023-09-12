/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:52:52 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 15:40:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_philosophers_deaths(
	t_philosopher *philosophers,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		while (get_philo_state(philosophers + i) != E_DEAD
			&& get_philo_state(philosophers + i) != E_FINISHED)
			usleep(TEMPO_TIME);
		++i;
	}
}

void	kill_all_philos(
	t_philosopher *philosophers,
	size_t first_id_philo_dead,
	const t_dinner_config *config
	)
{
	size_t	i;

	i = 0;
	while (i < config->nb_philosopher)
	{
		set_philo_state(philosophers + i, E_PREPARE_TO_DIE);
		if (i == first_id_philo_dead)
			print_philo_action(philosophers + i, DEAD_MESSAGE);
		++i;
	}
	wait_for_philosophers_deaths(philosophers, config);
}

bool	philosopher_should_die(
	t_philosopher *philo,
	const t_dinner_config *config
	)
{
	t_manager *const	manager = get_manager();
	size_t				time;
	bool				should_a_philosopher_die;

	should_a_philosopher_die = false;
	if (get_philo_state(philo) != E_FINISHED)
	{
		time = delta_time(get_time_since_last_dinner(philo));
		if (time >= config->die_time)
		{
			should_a_philosopher_die = true;
			manager->is_a_philosopher_dead = should_a_philosopher_die;
		}
	}
	return (should_a_philosopher_die);
}
