/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:05:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 19:03:54 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_config(t_dinner_config *config)
{

	printf("%-40s: %zu\n", NB_PHILO_MESSAGE, config->nb_philosopher);
	printf("%-40s: %zu\n", DIE_TIME_MESSAGE, config->die_time);
	printf("%-40s: %zu\n", EAT_TIME_MESSAGE, config->eat_time);
	printf("%-40s: %zu\n", SLEEP_TIME_MESSAGE, config->sleep_time);
	if (config->is_a_max_nb_dinner == true)
		printf("%-40s: infinite\n", NB_DINNER_MESSAGE);
	else
		printf("%-40s: %zu\n", NB_DINNER_MESSAGE, config->nb_dinner);
}
