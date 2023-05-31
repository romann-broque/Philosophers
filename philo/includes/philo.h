/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/31 18:09:31 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

///////////////
/// DEFINES ///
///////////////

// CLASSIC MESSAGES //

# define NB_PHILO_MESSAGE	"Numbers of philosophers"
# define DIE_TIME_MESSAGE	"Time to die (ms)"
# define EAT_TIME_MESSAGE	"Time to eat (ms)"
# define SLEEP_TIME_MESSAGE	"Time to sleep (ms)"
# define NB_DINER_MESSAGE	"Number of time each philosopher must eat"

// ERROR MESSAGES //

# define NOT_ENOUGH_ARG		"not enough arguments"
# define TOO_MANY_ARG		"too many arguments"

// COUNT //

# define MIN_EXPECTED_ARG	4
# define MAX_EXPECTED_ARG	5
# define INFINITE_DINER		-1

// COLORS //

# define NC					"\e[0m"
# define YELLOW				"\e[33m"
# define BYELLOW			"\e[1;33m"
# define RED				"\e[31m"
# define GREEN				"\e[32m"

// CHARACTERS //

# define SPACE				' '
# define FIRST_WHITESPACE	9
# define LAST_WHITESPACE	13

///////////////////
/// STRUCTURES ///
//////////////////

typedef struct s_stat
{
	size_t	nb_philo;
	size_t	die_time;
	size_t	eat_time;
	size_t	sleep_time;
	ssize_t	nb_diner;
}				t_stat;

//////////////////
/// FUNCTIONS ///
/////////////////

// ft_atoi.c

int		ft_atoi(const char *nptr);

// get_stat.c

int		get_stat(t_stat *stats, const int ac, char **av);

///		PRINT		///

// print_error.c

void	print_error(const char *str);

// print_stat.c

void	print_stat(t_stat *stats);

#endif
