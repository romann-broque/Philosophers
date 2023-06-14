/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:03:39 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 10:07:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_manager	*get_manager(t_manager *manager_ref)
{
	static t_manager	*manager = NULL;

	if (manager == NULL)
		manager = manager_ref;
	return (manager);
}