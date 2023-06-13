/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:17:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 19:24:53 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_forks(const size_t nb_forks)
{
	pthread_mutex_t	*forks;
	size_t			i;

	forks = (pthread_mutex_t *)malloc(nb_forks * sizeof(pthread_mutex_t));
	if (forks != NULL)
	{
		i = 0;
		while (i < nb_forks)
		{
			pthread_mutex_init(forks + i, NULL);
			++i;
		}
	}
	return (forks);
}
