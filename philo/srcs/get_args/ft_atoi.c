/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:19:25 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/31 17:55:43 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_whitespace(const char c)
{
	return (c == SPACE || (FIRST_WHITESPACE <= c && c <= LAST_WHITESPACE));
}

int	ft_atoi(const char *nptr)
{
	long	nb;
	size_t	i;

	nb = 0;
	while (is_whitespace(*nptr) == true)
		++nptr;
	i = 0;
	if (nptr[0] == '-' || nptr[0] == '+')
		++i;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		++i;
	}
	if (nptr[0] == '-')
		nb *= -1;
	return ((int)nb);
}
