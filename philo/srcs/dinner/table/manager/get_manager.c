/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:03:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 10:15:11 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_manager	*load_manager(t_manager *manager_ref)
{
	static t_manager	*manager = NULL;

	if (manager == NULL)
		manager = manager_ref;
	return (manager);
}

void	init_manager(t_manager *manager_ref)
{
	load_manager(manager_ref);
}

t_manager	*get_manager(void)
{
	return (load_manager(NULL));
}

