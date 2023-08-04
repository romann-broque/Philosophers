/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:02:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/08/04 12:25:49 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_dinner_config	*load_config(t_dinner_config *config_ref)
{
	static t_dinner_config	*config = NULL;

	if (config == NULL)
		config = config_ref;
	return (config);
}

void	init_config(t_dinner_config *config_ref)
{
	load_config(config_ref);
}

t_dinner_config	*get_config(void)
{
	return (load_config(NULL));
}
