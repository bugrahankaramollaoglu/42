/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nliman <nliman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:03:18 by nliman            #+#    #+#             */
/*   Updated: 2022/12/11 20:30:51 by nliman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philos_status(t_philo *philo, char *status, int kill)
{
	pthread_mutex_lock(philo->lock);
	if (!*philo->is_dead)
	{
		printf("%llu %d %s\n", (ft_get_time() - philo->start_time), \
		philo->id + 1, status);
		if (kill)
			*philo->is_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

void	eat_time_philos(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	print_philos_status(philo, "has taken a fork ", 0);
	pthread_mutex_lock(philo->right_fork_mutex);
	print_philos_status(philo, "has taken a fork", 0);
	if (ft_philo_check(philo))
		return ;
	print_philos_status(philo, "is eating", 0);
	pthread_mutex_lock(philo->lock);
	philo->last_meal = ft_get_time();
	philo->eaten++;
	pthread_mutex_unlock(philo->lock);
	waiting_philos(philo, philo->eat_time);
}

void	sleep_time_philos(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (ft_philo_check(philo))
		return ;
	print_philos_status(philo, "is sleeping", 0);
	waiting_philos(philo, philo->sleep_time);
}

void	*loops_for_philos(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	if (philo->philo_num == 1 && !ft_philo_check(philo))
	{
		if (pthread_mutex_lock(philo->left_fork_mutex))
			return (NULL);
		print_philos_status(philo, " has taken a fork", 0);
		while (!ft_philo_check(philo))
		{
		}
		pthread_mutex_unlock(philo->left_fork_mutex);
	}
	while (1)
	{
		if (ft_philo_check(philo))
			break ;
		eat_time_philos(philo);
		sleep_time_philos(philo);
		if (!ft_philo_check(philo))
			print_philos_status(philo, "is thinking", 0);
	}
	return (NULL);
}
