/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:15:09 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 21:34:10 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	init_table(t_dinner_config *config)
{
	t_table	table;

	table.forks = init_forks(config->nb_philosopher);
	table.philosophers = init_philosophers(config->nb_philosopher);
	return (table);
}
