/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:50:11 by cramos-c          #+#    #+#             */
/*   Updated: 2024/11/18 15:26:24 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	initializer_mutexs(t_global *global)
{
	pthread_mutex_init(&global->vars.mutexs.run_mutex, NULL);
	pthread_mutex_init(&global->vars.mutexs.printf_mutex, NULL);
	pthread_mutex_init(&global->vars.mutexs.limit_eat_mutex, NULL);
	pthread_mutex_init(&global->vars.mutexs.death_mutex, NULL);
	pthread_mutex_init(&global->vars.mutexs.all_eat_limit_mutex, NULL);
}

static void	destroy_mutexs(t_global *global)
{
	pthread_mutex_destroy(&global->vars.mutexs.run_mutex);
	pthread_mutex_destroy(&global->vars.mutexs.printf_mutex);
	pthread_mutex_destroy(&global->vars.mutexs.limit_eat_mutex);
	pthread_mutex_destroy(&global->vars.mutexs.death_mutex);
	pthread_mutex_destroy(&global->vars.mutexs.all_eat_limit_mutex);
}

static int	validator_args(t_global *global, int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 5 || argc > 6)
	{
		printf ("!!Invalid Arguements!!\n");
		return (0);
	}
	if (!is_valid_int(argv[1]) || !is_valid_int(argv[2]) \
	|| !is_valid_int(argv[3]) || !is_valid_int(argv[4]) \
	|| (argc == 6 && !is_valid_int(argv[5])))
	{
		printf ("!!Invalid Arguments!!\n");
		return (0);
	}
	global->vars.num_philos = ft_atoi(argv[1]);
	global->vars.die_time = ft_atoi(argv[2]);
	global->vars.eating_time = ft_atoi(argv[3]);
	global->vars.sleaping_time = ft_atoi(argv[4]);
	global->vars.is_running = 1;
	if (argc == 6)
		global->vars.limit_eating = ft_atoi(argv[5]);
	else
		global->vars.limit_eating = 0;
	return (1);
}

static void	cleanup_globals(t_global *global)
{
	int	i;

	i = 0;
	if (global->vars.num_philos > 1)
		pthread_join(global->vars.thread_minitor, NULL);
	while (i < global->vars.num_philos)
	{
		pthread_join(global->philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < global->vars.num_philos)
	{
		pthread_mutex_destroy(&global->forks[i]);
		i++;
	}
	destroy_mutexs(global);
	free (global->vars.all_eat_limit);
	free (global->forks);
	free (global->philos);
}

int	main(int argc, char *argv[])
{
	t_global	global;

	if (!validator_args(&global, argc, argv))
		return (0);
	initializer_mutexs(&global);
	if (!init_globals(&global))
	{
		printf ("!!Invalid Arguments!!\n");
		return (1);
	}
	cleanup_globals(&global);
	return (0);
}
