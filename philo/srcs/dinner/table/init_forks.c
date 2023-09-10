/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:17:19 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/10 07:38:33 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*init_forks(const size_t nb_forks)
{
	pthread_mutex_t *const	forks
		= (pthread_mutex_t *)malloc(nb_forks * sizeof(pthread_mutex_t));
	size_t					i;

	if (forks == NULL)
		return (NULL);
	i = 0;
	while (i < nb_forks)
	{
		if (pthread_mutex_init(forks + i, NULL))
		{
			clean_forks(forks, i);
			return (NULL);
		}
		++i;
	}
	return (forks);
}
