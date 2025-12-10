/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:41:03 by clouden           #+#    #+#             */
/*   Updated: 2025/12/10 19:44:43 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t t_mtx;

typedef struct s_table t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_if;
}	t_fork;

typedef struct	s_philo
{
	int			id;
	long		meals_eaten;
	bool		full;
	long		last_meal_start_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct	s_table
{
	long	num_of_philos;
	long	time_to_eat;
	long	time_to_die;
	long	time_to_sleep;
	long	must_eat;
	long	start_simulation_time;
	long	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
}	t_table;


void init_table(char *av[], t_table *table);

#endif
