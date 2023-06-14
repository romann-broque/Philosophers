/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 10:37:26 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_state(t_philosopher *philo, t_dinner_config *config)
{
	print_state(philo, EAT_MESSAGE);
	philo->time_since_last_dinner = get_time();
	exec_action(config->eat_time);
	++(philo->nb_dinner_eaten);
}

void	*philo_routine(t_philosopher *philo)
{
	t_dinner_config *const	config = get_config(NULL);
	t_manager *const		manager = get_manager(NULL);

	philo->time_since_last_dinner = manager->start_dinner_time;
	while (philo->nb_dinner_eaten < config->nb_dinner)
		eat_state(philo, config);
	return (philo);
}
