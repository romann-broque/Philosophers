/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:33:32 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/02 14:33:52 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_act(const size_t id, const char *action)
{
	struct timeval	tv;
	struct timezone	tz;

	printf("%d %zu %s\n", gettimeofday(&tv, &tz), id, action);
}
