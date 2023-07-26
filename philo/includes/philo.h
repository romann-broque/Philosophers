/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:34 by rbroque           #+#    #+#             */
/*   Updated: 2023/07/26 09:56:38 by rbroque          ###   ########.fr       */
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
# define NON_DIGIT_ERROR_MESSAGE	"parameters must be numbers"
# define BEYOND_LIMIT_ERROR_MESSAGE	"parameters must be numbers under LONG_MAX"

// COUNT //

# define MIN_EXPECTED_ARG	4
# define MAX_EXPECTED_ARG	5
# define STATE_NB			3

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
# define BEYOND_ULIMIT_MASK	0x1000

# define SUCCESS 0
# define FAILURE -1

////////////
/// ENUM ///
////////////

enum e_state
{
	E_SLEEP,
	E_THINK,
	E_EAT,
	E_PREPARE_TO_DIE,
	E_DEAD,
	E_FINISHED
};

///////////////////
/// STRUCTURES ///
//////////////////

typedef struct s_philosopher
{
	pthread_mutex_t	*forks[2];
	size_t			id;
	size_t			nb_dinner_eaten;
	size_t			time_since_last_dinner;
	pthread_mutex_t	state_locker;
	pthread_mutex_t	dinner_locker;
	enum e_state	state;
}				t_philosopher;

typedef struct s_manager
{
	size_t			start_dinner_time;
	pthread_mutex_t	speak_locker;
	pthread_mutex_t	is_over_locker;
	bool			is_a_philosopher_dead;
	bool			can_dinner_start;
}				t_manager;

typedef struct s_dinner_config
{
	pthread_t	*threads;
	size_t		nb_philosopher;
	size_t		die_time;
	size_t		eat_time;
	size_t		sleep_time;
	size_t		nb_dinner;
	bool		is_a_max_nb_dinner;
}				t_dinner_config;

typedef struct s_table
{
	t_manager			manager;
	pthread_mutex_t		*forks;
	t_philosopher		*philosophers;
}				t_table;

//////////////////
/// FUNCTIONS ///
/////////////////

///		dinner		///

// start_dinner.c

void			start_dinner(t_table *table, t_dinner_config *config);

// start_simulation.c

void			start_simulation(t_dinner_config *const config);

// philo_routine.c

void			*philo_routine(t_philosopher *philo);

////	table		////

/// init_forks.c

pthread_mutex_t	*init_forks(const size_t nb_forks);

/// set_manager.c

void			set_manager(t_manager *manager);

/// init_philosophers.c

t_philosopher	*init_philosophers(
					pthread_mutex_t *forks,
					const size_t nb_philosophers);

/// init_table.c

t_table			*init_table(t_dinner_config *config);

/// clean_table.c

void			clean_table(t_table *table);

/////	manager		/////

//// get_manager.c

void			init_manager(t_manager *manager_ref);
t_manager		*get_manager(void);

//// manager_routine.c

void			manager_routine(t_table *table, const t_dinner_config *config);

/////	philosopher		/////

//// philo_routine.c

void			*philo_routine(t_philosopher *philo);

//// set_philo_state.c

void			set_philo_state(t_philosopher *philo, const enum e_state state);
enum e_state get_philo_state(t_philosopher *philo);

/////	states			//////

///// eat_state.c

void			eat_state(t_philosopher *philo, t_dinner_config *config);

///// sleep_state.c

void			sleep_state(t_philosopher *philo, t_dinner_config *config);

///// think_state.c

void			think_state(t_philosopher *philo, t_dinner_config *config);

///		GET_ARGS	///

// ft_atolu_check.c

int				ft_atolu_check(unsigned long *ret_value, const char *str);

// init_config.c

int				init_config(t_dinner_config *config, const int ac, char **av);
t_dinner_config	*get_config(t_dinner_config *config_ref);

///		PRINT		///

// print_error.c

void			print_error(const char *str);

// print_config.c

void			print_config(t_dinner_config *config);

// print_philo_action.c

void			print_philo_action(t_philosopher *philo, const char *message);

///		TIME		///

// time_utils.c

size_t			get_time(void);
size_t			delta_time(long long time);
void			exec_action(const size_t micro_seconds);

#endif
