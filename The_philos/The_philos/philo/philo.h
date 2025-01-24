/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:36:30 by cramos-c          #+#    #+#             */
/*   Updated: 2024/11/18 14:52:29 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

// Define constants for readability
# define FORK 1
# define EATING 2
# define SLEEP 3
# define THINKING 4
# define DIED 5

typedef struct s_mutexs
{
	pthread_mutex_t	printf_mutex;
	pthread_mutex_t	all_eat_limit_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	run_mutex;
	pthread_mutex_t	limit_eat_mutex;
}	t_mutexs;

typedef struct s_vars {
	t_mutexs	mutexs;
	int			num_philos;
	int			die_time;
	int			eating_time;
	int			sleaping_time;
	int			is_running;
	long		start_time;
	int			limit_eating;
	int			*all_eat_limit;
	pthread_t	thread_minitor;
}	t_vars;

typedef struct s_philo
{
	long			last_meal_time;
	pthread_mutex_t	*fork_left;
	t_vars			*vars;
	pthread_mutex_t	*fork_right;
	pthread_t		thread;
	int				id;
	int				eating_times;
}	t_philo;

typedef struct s_global
{
	t_vars			vars;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_global;

size_t	current_time(void);

void	*monitor_philos(void *arg);
void	*philo_routine(void *param);
int		philo_actions(t_philo *philo, int flag);
void	*handle_single_philosopher(t_philo *philo);
int		init_globals(t_global *global);
int		ft_isdigit(int d);
int		is_valid_int(const char *str);
int		ft_atoi(const char *str);

#endif
