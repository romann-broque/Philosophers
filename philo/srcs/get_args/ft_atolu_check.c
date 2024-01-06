/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:14:02 by rbroque           #+#    #+#             */
/*   Updated: 2023/09/12 15:47:25 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_whitespace(const char c)
{
	return (c == SPACE || (FIRST_WHITESPACE <= c && c <= LAST_WHITESPACE));
}

static bool	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_inbounds(
	const unsigned long nb,
	const unsigned long added_nb
	)
{
	const unsigned long	bound = (INT_MAX - added_nb) / 10;

	return (nb <= bound);
}

static int	skip_beginning(const char **str)
{
	int	ret_val;

	ret_val = EXIT_SUCCESS;
	while (is_whitespace(**str) == true)
		++*str;
	if (**str == '-')
		ret_val |= NEGATIVE_MASK;
	*str += (**str == '-' || **str == '+');
	return (ret_val);
}

int	ft_atolu_check(unsigned long *nb_dest, const char *str)
{
	int		ret_val;
	long	nb;

	ret_val = skip_beginning(&str);
	nb = 0;
	while (ft_isdigit(*str) != 0)
	{
		if (is_inbounds(nb, *str - '0') == false)
		{
			if (!(ret_val & NEGATIVE_MASK))
				ret_val = BEYOND_LIMIT_MASK;
			break ;
		}
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (*str == '\0')
		*nb_dest = nb;
	else if (ret_val == EXIT_SUCCESS)
		ret_val = NON_DIGIT_MASK;
	return (ret_val);
}
