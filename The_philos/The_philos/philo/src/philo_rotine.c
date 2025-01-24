/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rotine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:00:49 by cramos-c          #+#    #+#             */
/*   Updated: 2024/11/18 14:45:20 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		usleep(1000);
		pthread_mutex_lock(philo->fork_right);
		philo_actions(philo, FORK);
		pthread_mutex_lock(philo->fork_left);
		philo_actions(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		philo_actions(philo, FORK);
		pthread_mutex_lock(philo->fork_right);
		philo_actions(philo, FORK);
	}
}

static int	has_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->vars->mutexs.death_mutex);
	if ((current_time() - philo->last_meal_time) > (philo->vars->die_time + 3))
	{
		pthread_mutex_unlock(&philo->vars->mutexs.death_mutex);
		philo_actions(philo, DIED);
		pthread_mutex_lock(&philo->vars->mutexs.run_mutex);
		philo->vars->is_running = 0;
		pthread_mutex_unlock(&philo->vars->mutexs.run_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->vars->mutexs.death_mutex);
	return (0);
}

int	check_all_eat(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->vars.num_philos)
	{
		pthread_mutex_lock(&global->vars.mutexs.all_eat_limit_mutex);
		if (!global->vars.all_eat_limit[i])
		{
			pthread_mutex_unlock(&global->vars.mutexs.all_eat_limit_mutex);
			return (0);
		}
		pthread_mutex_unlock(&global->vars.mutexs.all_eat_limit_mutex);
		i++;
	}
	pthread_mutex_lock(&global->vars.mutexs.run_mutex);
	global->vars.is_running = 0;
	pthread_mutex_unlock(&global->vars.mutexs.run_mutex);
	return (1);
}

void	*monitor_philos(void *arg)
{
	t_global	*global;
	int			i;

	global = (t_global *)arg;
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&global->vars.mutexs.run_mutex);
		if (!global->vars.is_running)
		{
			pthread_mutex_unlock(&global->vars.mutexs.run_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&global->vars.mutexs.run_mutex);
		i = 0;
		while (i < global->vars.num_philos)
		{
			if (has_die(&global->philos[i]))
				return (NULL);
			if (check_all_eat(global))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->vars->num_philos == 1)
		return (handle_single_philosopher(philo));
	while (1)
	{
		pthread_mutex_lock(&philo->vars->mutexs.run_mutex);
		if (!philo->vars->is_running)
			return (pthread_mutex_unlock(&philo->vars->mutexs.run_mutex), NULL);
		pthread_mutex_unlock(&philo->vars->mutexs.run_mutex);
		pthread_mutex_lock(&philo->vars->mutexs.all_eat_limit_mutex);
		if (philo->vars->all_eat_limit[philo->id - 1])
			return (pthread_mutex_unlock(\
			&philo->vars->mutexs.all_eat_limit_mutex), NULL);
		pthread_mutex_unlock(&philo->vars->mutexs.all_eat_limit_mutex);
		(take_forks(philo), philo_actions(philo, EATING));
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		philo_actions(philo, SLEEP);
		usleep(philo->vars->sleaping_time * 1000);
		philo_actions(philo, THINKING);
	}
	return (NULL);
}
