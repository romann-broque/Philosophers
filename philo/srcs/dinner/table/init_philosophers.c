/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:22:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 19:33:48 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philosopher	*set_philo(
	t_philosopher *philo,
	const size_t id,
	pthread_mutex_t *forks[2]
	)
{
	philo->id = id;
	if (pthread_mutex_init(&(philo->state_locker), NULL) != ALLOC_SUCCESS)
		return (NULL);
	if (pthread_mutex_init(&(philo->nb_dinner_locker), NULL) != ALLOC_SUCCESS)
	{
		pthread_mutex_destroy(&(philo->state_locker));
		return (NULL);
	}
	if (pthread_mutex_init(&(philo->time_locker), NULL) != ALLOC_SUCCESS)
	{
		pthread_mutex_destroy(&(philo->state_locker));
		pthread_mutex_destroy(&(philo->nb_dinner_locker));
		return (NULL);
	}
	philo->state = E_THINK;
	philo->nb_dinner_eaten = 0;
	philo->time_since_last_dinner = 0;
	philo->forks[philo->id % 2] = forks[0];
	philo->forks[(philo->id + 1) % 2] = forks[1];
	return (philo);
}

static void	clean_philo(t_philosopher *philosophers, const size_t max_id)
{
	size_t	i;

	i = 0;
	while (i + 1 < max_id)
	{
		pthread_mutex_destroy(&(philosophers[i].state_locker));
		pthread_mutex_destroy(&(philosophers[i].nb_dinner_locker));
		pthread_mutex_destroy(&(philosophers[i].time_locker));
		++i;
	}
}

static t_retval	set_philosophers(
	t_philosopher *philosophers,
	pthread_mutex_t *forks,
	const size_t nb_philosophers
	)
{
	pthread_mutex_t	*fork_couple[2];
	size_t			i;
	size_t			id;

	i = 0;
	while (i < nb_philosophers)
	{
		id = i + 1;
		fork_couple[0] = forks + i;
		fork_couple[1] = forks + id % nb_philosophers;
		if (set_philo(philosophers + i, id, fork_couple) == NULL)
		{
			clean_philo(philosophers, i);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

t_philosopher	*init_philosophers(
	pthread_mutex_t *forks,
	const size_t nb_philosophers
	)
{
	t_philosopher	*philosophers;

	philosophers = (t_philosopher *)malloc(
			nb_philosophers * sizeof(t_philosopher));
	if (philosophers != NULL
		&& set_philosophers(philosophers, forks, nb_philosophers)
		== EXIT_FAILURE)
		free(philosophers);
	return (philosophers);
}
