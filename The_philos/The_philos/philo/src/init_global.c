/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:04:24 by cramos-c          #+#    #+#             */
/*   Updated: 2024/11/16 18:49:34 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	init_philos(t_global *global, int i, size_t time)
{
	global->philos[i].id = i + 1;
	global->philos[i].fork_left = &global->forks[i];
	global->philos[i].fork_right = &global->forks[(i + 1) % \
	global->vars.num_philos];
	global->philos[i].last_meal_time = time;
	global->philos[i].eating_times = 0;
	global->philos[i].vars = &global->vars;
	pthread_create(&global->philos[i].thread, \
	NULL, philo_routine, &global->philos[i]);
}

int	init_globals(t_global *global)
{
	int	i;

	global->vars.is_running = 1;
	global->vars.start_time = current_time();
	global->forks = malloc(sizeof(pthread_mutex_t) * global->vars.num_philos);
	global->philos = malloc(sizeof(t_philo) * global->vars.num_philos);
	global->vars.all_eat_limit = malloc(sizeof(int) * global->vars.num_philos);
	if (global->forks == NULL || global->philos == NULL)
		return (0);
	i = 0;
	while (i < global->vars.num_philos)
	{
		pthread_mutex_init(&global->forks[i], NULL);
		global->vars.all_eat_limit[i] = 0;
		i++;
	}
	i = 0;
	while (i < global->vars.num_philos)
		init_philos(global, i++, global->vars.start_time);
	if (global->vars.num_philos > 1)
		pthread_create(&global->vars.thread_minitor, \
		NULL, monitor_philos, global);
	return (1);
}
