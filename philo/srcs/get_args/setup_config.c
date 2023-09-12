/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:25:20 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 14:14:59 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_arg_error(const int error)
{
	if (error & NEGATIVE_MASK)
		print_error(SIGN_EMESSAGE);
	if (error & NON_DIGIT_MASK)
		print_error(NON_DIGIT_EMESSAGE);
	if (error & BEYOND_LIMIT_MASK)
		print_error(BEYOND_LIMIT_EMESSAGE);
	if (error & TOO_MANY_PHILO_MASK)
		print_error(TOO_MANY_PHILO_EMESSAGE);
}

static int	set_config_value(t_dinner_config *config, char **av)
{
	int	error_val;

	error_val = NO_ERROR;
	error_val |= ft_atolu_check(&(config->nb_philosopher), av[0]);
	if (!(error_val & NEGATIVE_MASK) && config->nb_philosopher > PHILO_COUNT_MAX)
		error_val |= TOO_MANY_PHILO_MASK;
	error_val |= ft_atolu_check(&(config->die_time), av[1]);
	error_val |= ft_atolu_check(&(config->eat_time), av[2]);
	error_val |= ft_atolu_check(&(config->sleep_time), av[3]);
	if (av[4] != NULL)
		error_val |= ft_atolu_check(&(config->nb_dinner), av[4]);
	else
		config->nb_dinner = INT_MAX;
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

int	setup_config(t_dinner_config *config, const int ac, char **av)
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
