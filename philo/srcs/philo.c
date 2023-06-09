/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:34:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/01 19:37:45 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_stat	stats;
	int		ret_val;

	++av;
	--ac;
	ret_val = get_stat(&stats, ac, av);
	if (ret_val == EXIT_SUCCESS)
		start_diner(&stats);
	return (ret_val);
}
