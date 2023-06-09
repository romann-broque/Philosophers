/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:02:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/09 14:38:02 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_arg_error(const int error)
{
	if (error & NEGATIVE_MASK)
		print_error(SIGN_ERROR_MESSAGE);
	if (error & NON_DIGIT_MASK)
		print_error(NON_DIGIT_ERROR_MESSAGE);
	if (error & BEYOND_LIMIT_MASK)
		print_error(BEYOND_LIMIT_ERROR_MESSAGE);
}

static int	get_stat_value(t_stat *stats, char **av)
{
	int	error_val;

	error_val = NO_ERROR;
	error_val |= ft_atolu_check(&(stats->nb_philo), av[0]);
	error_val |= ft_atolu_check(&(stats->die_time), av[1]);
	error_val |= ft_atolu_check(&(stats->eat_time), av[2]);
	error_val |= ft_atolu_check(&(stats->sleep_time), av[3]);
	if (av[4] != NULL)
		error_val |= ft_atolu_check((size_t *)&(stats->nb_dinner), av[4]);
	else
		stats->nb_dinner = INFINITE_DINNER;
	return (error_val);
}

static int	init_stats(t_stat *stats, char **av)
{
	int	error_val;

	error_val = get_stat_value(stats, av);
	if (error_val == NO_ERROR)
		return (EXIT_SUCCESS);
	print_arg_error(error_val);
	return (EXIT_FAILURE);
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
		ret_val = init_stats(stats, av);
	return (ret_val);
}
