/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <cramos-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 21:11:13 by cramos-c          #+#    #+#             */
/*   Updated: 2024/11/18 14:49:46 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*handle_single_philosopher(t_philo *philo)
{
	printf("[0 ms] 1 has taken a fork.\n");
	usleep(philo->vars->die_time * 1000);
	printf("[%d ms] 1 has died.\n", philo->vars->die_time);
	return (NULL);
}

static int	eat_action(t_philo *philo)
{	
	pthread_mutex_lock(&philo->vars->mutexs.death_mutex);
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(&philo->vars->mutexs.death_mutex);
	usleep(philo->vars->eating_time * 1000);
	pthread_mutex_lock(&philo->vars->mutexs.limit_eat_mutex);
	philo->eating_times++;
	pthread_mutex_unlock(&philo->vars->mutexs.limit_eat_mutex);
	pthread_mutex_lock(&philo->vars->mutexs.limit_eat_mutex);
	if ((philo->vars->limit_eating > 0) && \
	(philo->vars->limit_eating == philo->eating_times))
	{
		pthread_mutex_lock(&philo->vars->mutexs.all_eat_limit_mutex);
		philo->vars->all_eat_limit[philo->id - 1] = 1;
		pthread_mutex_unlock(&philo->vars->mutexs.all_eat_limit_mutex);
	}
	return (pthread_mutex_unlock(&philo->vars->mutexs.limit_eat_mutex));
}

int	philo_actions(t_philo *philo, int flag)
{
	pthread_mutex_lock(&philo->vars->mutexs.run_mutex);
	if (!philo->vars->is_running)
		return (pthread_mutex_unlock(&philo->vars->mutexs.run_mutex));
	pthread_mutex_unlock(&philo->vars->mutexs.run_mutex);
	pthread_mutex_lock(&philo->vars->mutexs.printf_mutex);
	if (flag == FORK)
		printf("[%ld ms] %d has taken a fork\n", current_time() \
		- philo->vars->start_time, philo->id);
	else if (flag == EATING)
	{
		printf("[%ld ms] %d is eating\n", current_time() \
		- philo->vars->start_time, philo->id);
		pthread_mutex_unlock(&philo->vars->mutexs.printf_mutex);
		return (eat_action(philo));
	}
	else if (flag == SLEEP)
		printf("[%ld ms] %d is sleeping\n", current_time() \
		- philo->vars->start_time, philo->id);
	else if (flag == THINKING)
		printf("[%ld ms] %d is thinking\n", current_time() \
		- philo->vars->start_time, philo->id);
	else if (flag == DIED)
		printf("[%ld ms] %d died\n", current_time() \
		- philo->vars->start_time, philo->id);
	return (pthread_mutex_unlock(&philo->vars->mutexs.printf_mutex));
}
