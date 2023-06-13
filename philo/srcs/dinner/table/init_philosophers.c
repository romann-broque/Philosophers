/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:22:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 21:39:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philosopher(t_philosopher *philo, const size_t id)
{
	philo->id = id;
	philo->state = E_THINK;
	philo->nb_dinner_eaten = 0;
}

t_philosopher	*init_philosophers(const size_t nb_philosophers)
{
	t_philosopher	*philosophers;
	size_t			i;

	philosophers = (t_philosopher *)malloc(
			nb_philosophers * sizeof(t_philosopher));
	if (philosophers != NULL)
	{
		i = 0;
		while (i < nb_philosophers)
		{
			set_philosopher(philosophers + i, i + 1);
			++i;
		}
	}
	return (philosophers);
}
