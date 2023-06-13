/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:16:46 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 01:44:32 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_state(t_philosopher *philo)
{
	print_state(philo, EAT_MESSAGE);
	++(philo->nb_dinner_eaten);
}

void	*philo_routine(t_philosopher *philo)
{
	t_dinner_config *const	config = get_config(NULL);

	while (philo->nb_dinner_eaten < config->nb_dinner)
		eat_state(philo);
	return (philo);
}
