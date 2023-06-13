/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:22:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 22:48:08 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo(
	t_philosopher *philo,
	const size_t id,
	pthread_mutex_t *forks[2]
	)
{
	philo->id = id;
	philo->state = E_THINK;
	philo->nb_dinner_eaten = 0;
	philo->left_fork = forks[0];
	philo->right_fork = forks[1];
	philo->nb_dinner_eaten = 0;
}

static void	set_philosophers(
	t_philosopher *philosophers,
	pthread_mutex_t *forks,
	const size_t nb_philosophers
	)
{
	pthread_mutex_t	*fork_couple[2];
	size_t			i;

	i = 0;
	while (i < nb_philosophers)
	{
		fork_couple[0] = forks + i;
		fork_couple[1] = forks + i % nb_philosophers;
		set_philo(philosophers + i, i + 1, fork_couple);
		++i;
	}
}

t_philosopher	*init_philosophers(
	pthread_mutex_t *forks,
	const size_t nb_philosophers
	)
{
	t_philosopher	*philosophers;

	philosophers = (t_philosopher *)malloc(
			nb_philosophers * sizeof(t_philosopher));
	if (philosophers != NULL)
		set_philosophers(philosophers, forks, nb_philosophers);
	return (philosophers);
}
