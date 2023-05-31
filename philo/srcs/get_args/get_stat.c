/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:02:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/31 18:08:18 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_stats(t_stat *stats, char **av)
{
	stats->nb_philo = ft_atoi(av[0]);
	stats->die_time = ft_atoi(av[1]);
	stats->eat_time = ft_atoi(av[2]);
	stats->sleep_time = ft_atoi(av[3]);
	if (av[4] != NULL)
		stats->nb_diner = ft_atoi(av[4]);
	else
		stats->nb_diner = INFINITE_DINER;
}

int	get_stat(t_stat *stats, const int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac < MIN_EXPECTED_ARG)
		print_error(NOT_ENOUGH_ARG);
	else if (ac > MAX_EXPECTED_ARG)
		print_error(TOO_MANY_ARG);
	else
	{
		init_stats(stats, av);
		print_stat(stats);
		ret_val = EXIT_SUCCESS;
	}
	return (ret_val);
}
