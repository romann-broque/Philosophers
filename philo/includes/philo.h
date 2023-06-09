/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/06/09 14:38:41 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

///////////////
/// DEFINES ///
///////////////

// CLASSIC MESSAGES //

# define NB_PHILO_MESSAGE	"Numbers of philosophers"
# define DIE_TIME_MESSAGE	"Time to die (ms)"
# define EAT_TIME_MESSAGE	"Time to eat (ms)"
# define SLEEP_TIME_MESSAGE	"Time to sleep (ms)"
# define NB_DINNER_MESSAGE	"Number of time each philosopher must eat"
# define FORK_MESSAGE		"has taken a fork"
# define EAT_MESSAGE		"is eating"
# define SLEEP_MESSAGE		"is sleeping"
# define THINK_MESSAGE		"is thinking"
# define DEAD_MESSAGE		"died"

// ERROR MESSAGES //

# define NOT_ENOUGH_ARG				"not enough arguments"
# define TOO_MANY_ARG				"too many arguments"
# define SIGN_ERROR_MESSAGE			"numbers must be positive"
# define NON_DIGIT_ERROR_MESSAGE	"arguments must be numbers"
# define BEYOND_LIMIT_ERROR_MESSAGE	"arguments must be numbers under ULONG_MAX"

// COUNT //

# define MIN_EXPECTED_ARG	4
# define MAX_EXPECTED_ARG	5
# define INFINITE_DINNER	-1

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

typedef enum s_fork_state
{
	TAKEN,
	FREE
}			t_fork_state;

///////////////////
/// STRUCTURES ///
//////////////////

typedef struct s_fork
{
	t_fork_state	state;
	pthread_mutex_t	mutex;
}				t_fork;

typedef struct s_stat
{
	size_t	nb_philo;
	size_t	die_time;
	size_t	eat_time;
	size_t	sleep_time;
	ssize_t	nb_dinner;
}				t_stat;

typedef struct s_philo
{
	size_t			index;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_state			state;
	size_t			left_dinner;
	size_t			*start_time;
	suseconds_t		sleep_time;
	suseconds_t		eat_time;
	suseconds_t		time_count;
	pthread_t		thread;
	pthread_mutex_t	print_mutex;
	bool			*sbd_dead;
	bool			*can_start;
}				t_philo;

typedef struct s_table
{
	t_stat			*stats;
	t_fork			*forks;
	t_philo			*philo_array;
	pthread_t		dead_thread;
	pthread_mutex_t	action_mutex;
	bool			sbd_dead;
	bool			can_start;
	size_t			start_time;
}				t_table;

//////////////////
/// FUNCTIONS ///
/////////////////

///		dinner		///

// clean_table.c

void	clean_table(t_table *table);

// init_philo.c

t_philo	*init_philo_array(const size_t nb_philo, t_fork *forks);
void	set_philo_settings(t_table *table);

// init_table.c

void	init_table(t_table *table, t_stat *stats);

// start_dinner.c

void	start_dinner(t_stat *stats);

////	DEAD_ACTION		////

/// dead_routine.c

void	*dead_routine(t_table *table);

/// dead_routine_utils.c

void	*dead_philo_routine(t_philo *philo, t_stat *stats);
bool	is_dinner_finished(t_table *table);

////	TIME		////

/// time_utils.c

size_t	get_time(void);
size_t	delta_time(long long time);
void	exec_action(const size_t ms);

////		PHILO_ACTION		////

/// philo_routine.c

void	*philo_routine(t_philo *philo);

/// philo_states.c

void	eat_state(t_philo *philo);
void	sleep_state(t_philo *philo);
void	think_state(t_philo *philo);

///		GET_ARGS	///

// ft_atolu_check.c

int		ft_atolu_check(unsigned long *ret_value, const char *str);

// get_stat.c

int		get_stat(t_stat *stats, const int ac, char **av);

///		PRINT		///

// print_philo_act.c

void	print_philo_act(t_philo *philo, const char *action);

// print_error.c

void	print_error(const char *str);

// print_stat.c

void	print_stat(t_stat *stats);

#endif
