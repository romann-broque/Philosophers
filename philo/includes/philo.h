/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/01 20:24:04 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
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

# define NOT_ENOUGH_ARG				"not enough arguments"
# define TOO_MANY_ARG				"too many arguments"
# define SIGN_ERROR_MESSAGE			"numbers must be positive"
# define NON_DIGIT_ERROR_MESSAGE	"arguments must be numbers"
# define BEYOND_LIMIT_ERROR_MESSAGE	"arguments must be numbers under ULONG_MAX"

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

// MASK //

# define NO_ERROR			0x0000
# define NEGATIVE_MASK		0x0001
# define NON_DIGIT_MASK		0x0010
# define BEYOND_LIMIT_MASK	0x0100

////////////
/// ENUM ///
////////////

typedef enum s_state
{
	E_SLEEP,
	E_THINK,
	E_EAT,
	E_DEAD
}			t_state;

typedef enum s_fork
{
	TAKEN,
	FREE
}			t_fork;

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

typedef struct s_philo
{
	size_t	index;
	t_fork	*left_fork;
	t_fork	*right_fork;
	t_state	state;
}				t_philo;

typedef struct s_table
{
	t_stat	*stats;
	t_fork	*forks;
	t_philo	*philo_array;
}				t_table;

//////////////////
/// FUNCTIONS ///
/////////////////

///		DINER		///

// clean_table.c

void	clean_table(t_table *table);

// init_table.c

void	init_table(t_table *table, t_stat *stats);

// start_diner.c

void	start_diner(t_stat *stats);

///		GET_ARGS	///

// ft_atolu_check.c

int		ft_atolu_check(unsigned long *ret_value, const char *str);

// get_stat.c

int		get_stat(t_stat *stats, const int ac, char **av);

///		PRINT		///

// print_error.c

void	print_error(const char *str);

// print_stat.c

void	print_stat(t_stat *stats);

#endif
