/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:34:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/13 22:26:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_dinner_config	config;
	int				ret_val;

	++av;
	--ac;
	ret_val = get_config(&config, ac, av);
	if (ret_val == EXIT_SUCCESS)
		start_simulation(&config);
	return (ret_val);
}
