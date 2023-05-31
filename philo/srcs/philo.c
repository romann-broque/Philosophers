/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:34:24 by rbroque           #+#    #+#             */
/*   Updated: 2023/05/31 16:15:03 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define NC		"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define COUNT	10000

typedef struct s_count
{
	pthread_mutex_t	mutex;
	int				count;
}				t_count;

static void	*thread_routine(void *arg)
{
	t_count *const	count_struct = arg;
	int				*nb;
	size_t			i;

	i = 0;
	nb = &(count_struct->count);
	while (i < COUNT)
	{
		pthread_mutex_lock(&(count_struct->mutex));
		++(*nb);
		pthread_mutex_unlock(&(count_struct->mutex));
		++i;
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t		t1;
	pthread_t		t2;
	t_count			count_struct;
	size_t			i;

	(void)ac;
	(void)av;
	i = 0;
	while (i < 20)
	{
		count_struct.count = 0;
		pthread_mutex_init(&(count_struct.mutex), NULL);
		pthread_create(&t1, NULL, thread_routine, &count_struct);
		pthread_create(&t2, NULL, thread_routine, &count_struct);
		pthread_join(t1, NULL);
		pthread_join(t2, NULL);
		pthread_mutex_destroy(&(count_struct.mutex));
		if (count_struct.count == 2 * COUNT)
			printf("%sSUCCESS !%s\n", GREEN, NC);
		else
			printf("%sFAILURE%s: %d (EXPECTED -> %d)\n",
				RED, NC, count_struct.count, 2 * COUNT);
		++i;
	}
	return (EXIT_SUCCESS);
}
