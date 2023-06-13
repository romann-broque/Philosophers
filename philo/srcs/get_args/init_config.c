/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:02:41 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/14 01:57:06 by rbroque          ###   ########.fr       */
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

static int	set_config_value(t_dinner_config *config, char **av)
{
	int	error_val;

	error_val = NO_ERROR;
	error_val |= ft_atolu_check(&(config->nb_philosopher), av[0]);
	error_val |= ft_atolu_check(&(config->die_time), av[1]);
	error_val |= ft_atolu_check(&(config->eat_time), av[2]);
	error_val |= ft_atolu_check(&(config->sleep_time), av[3]);
	if (av[4] != NULL)
		error_val |= ft_atolu_check((size_t *)&(config->nb_dinner), av[4]);
	else
		config->nb_dinner = ULONG_MAX;
	config->is_a_max_nb_dinner = (av[4] == NULL);
	return (error_val);
}

static int	set_config(t_dinner_config *config, char **av)
{
	int	error_val;

	error_val = set_config_value(config, av);
	if (error_val == NO_ERROR)
		return (EXIT_SUCCESS);
	print_arg_error(error_val);
	return (EXIT_FAILURE);
}

int	init_config(t_dinner_config *config, const int ac, char **av)
{
	int	ret_val;

	ret_val = EXIT_FAILURE;
	if (ac < MIN_EXPECTED_ARG)
		print_error(NOT_ENOUGH_ARG);
	else if (ac > MAX_EXPECTED_ARG)
		print_error(TOO_MANY_ARG);
	else
		ret_val = set_config(config, av);
	return (ret_val);
}

t_dinner_config	*get_config(t_dinner_config *config_ref)
{
	static t_dinner_config	*config = NULL;

	if (config == NULL)
		config = config_ref;
	return (config);
}
