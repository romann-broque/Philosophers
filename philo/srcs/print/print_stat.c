/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:05:17 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/09 14:39:20 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_stat(t_stat *stats)
{
	printf("%-40s: %zu\n", NB_PHILO_MESSAGE, stats->nb_philo);
	printf("%-40s: %zu\n", DIE_TIME_MESSAGE, stats->die_time);
	printf("%-40s: %zu\n", EAT_TIME_MESSAGE, stats->eat_time);
	printf("%-40s: %zu\n", SLEEP_TIME_MESSAGE, stats->sleep_time);
	if (stats->nb_dinner == INFINITE_DINNER)
		printf("%-40s: infinite\n", NB_DINNER_MESSAGE);
	else
		printf("%-40s: %zu\n", NB_DINNER_MESSAGE, stats->nb_dinner);
}
