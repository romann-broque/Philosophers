/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:40:48 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/03 13:50:15 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	grab_specific_fork(t_philosopher *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (get_philo_state(philo) != E_PREPARE_TO_DIE)
		print_philo_action(philo, FORK_MESSAGE);
}

static int	grab_forks(t_philosopher *philo)
{
	grab_specific_fork(philo, philo->forks[0]);
	if (philo->forks[0] == philo->forks[1])
		return (FAILURE);
	grab_specific_fork(philo, philo->forks[1]);
	return (SUCCESS);
}

static void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->forks[0]);
	if (philo->forks[0] != philo->forks[1])
		pthread_mutex_unlock(philo->forks[1]);
}

static void	reset_eat_status(t_philosopher *philo)
{
	set_time_since_last_dinner(philo, get_time());
}

static void	increase_meal_count(t_philosopher *philo)
{
	increase_nb_dinner_eaten(philo);
}

void	eat_state(t_philosopher *philo, t_dinner_config *config)
{
	if (grab_forks(philo) == FAILURE)
		set_philo_state(philo, E_PREPARE_TO_DIE);
	else if (get_philo_state(philo) != E_PREPARE_TO_DIE)
	{
		reset_eat_status(philo);
		set_philo_state(philo, E_EAT);
		print_philo_action(philo, EAT_MESSAGE);
		exec_action(config->eat_time);
		increase_meal_count(philo);
		if (get_nb_dinner_eaten(philo) == config->nb_dinner)
			set_philo_state(philo, E_FINISHED);
	}
	drop_forks(philo);
}
